// All sound player by GPT
#include "sound.h"
#include <AudioToolbox/AudioToolbox.h>
#include <atomic>
#include <thread>
#include <chrono>
#include <cstring>
using namespace std;

static atomic<bool> keepPlaying(false);
static thread playerThread;

struct PlayerContext {
    AudioFileID audioFile = nullptr;
    AudioQueueRef queue = nullptr;
    UInt64 packetPos = 0;
    AudioStreamPacketDescription* packetDescs = nullptr;
    UInt32 maxPacketSize = 0;
    UInt32 numPacketsToRead = 1024;
};

static void AQOC(void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer) {
    PlayerContext* ctx = (PlayerContext*)inUserData;
    if (!keepPlaying.load()) {
        AudioQueueStop(ctx->queue, false);
        return;
    }
    UInt32 numBytes = 0;
    UInt32 numPackets = ctx->numPacketsToRead;
    OSStatus status = AudioFileReadPackets(ctx->audioFile, false, &numBytes, ctx->packetDescs, ctx->packetPos, &numPackets, inBuffer->mAudioData);
    if (status != noErr || numPackets == 0) {
        ctx->packetPos = 0;
        status = AudioFileReadPackets(ctx->audioFile, false, &numBytes, ctx->packetDescs, ctx->packetPos, &numPackets, inBuffer->mAudioData);
        if (status != noErr) {
            return;
        }
    }
    inBuffer->mAudioDataByteSize = numBytes;
    AudioQueueEnqueueBuffer(inAQ, inBuffer, 0, nullptr);
    ctx->packetPos += numPackets;
}

static void playerFunc(string filepath) {
    PlayerContext ctx = {};
    CFURLRef fileURL = CFURLCreateFromFileSystemRepresentation(nullptr, (const UInt8*)filepath.c_str(), (CFIndex)filepath.size(), false);
    if (AudioFileOpenURL(fileURL, kAudioFileReadPermission, 0, &ctx.audioFile) != noErr) {
        CFRelease(fileURL);
        return;
    }
    CFRelease(fileURL);
    UInt32 size = sizeof(AudioStreamBasicDescription);
    AudioStreamBasicDescription format = {};
    if (AudioFileGetProperty(ctx.audioFile, kAudioFilePropertyDataFormat, &size, &format) != noErr) {
        return;
    }
    if (AudioQueueNewOutput(&format, AQOC, &ctx, nullptr, nullptr, 0, &ctx.queue) != noErr) {
        return;
    }
    UInt32 maxPacketSize = 0;
    size = sizeof(maxPacketSize);
    AudioFileGetProperty(ctx.audioFile, kAudioFilePropertyPacketSizeUpperBound, &size, &maxPacketSize);
    ctx.maxPacketSize = maxPacketSize;
    UInt32 bufferByteSize = maxPacketSize * ctx.numPacketsToRead;
    ctx.packetDescs = new AudioStreamPacketDescription[ctx.numPacketsToRead];
    for (int i = 0; i < 3; ++i) {
        AudioQueueBufferRef buffer;
        AudioQueueAllocateBuffer(ctx.queue, bufferByteSize, &buffer);
        AQOC(&ctx, ctx.queue, buffer);
    }
    AudioQueueStart(ctx.queue, nullptr);
    while (keepPlaying.load()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    AudioQueueStop(ctx.queue, true);
    AudioQueueDispose(ctx.queue, true);
    AudioFileClose(ctx.audioFile);
    delete[] ctx.packetDescs;
}

void PlaySound(const string& soundFile) {
    if (keepPlaying.load()) return;
    keepPlaying = true;
    playerThread = thread(playerFunc, "assets/musics/" + soundFile);
}

void StopSound() {
    if (!keepPlaying.load()) return;
    keepPlaying = false;
    if (playerThread.joinable()) playerThread.join();
}