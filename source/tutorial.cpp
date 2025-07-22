#include <windows.h>
#include <iostream>
#include <string>
#include <limits>
#include "tutorial.h"
#include "cmd.h"
#include "porthack.h"
using namespace std;

void Tutorial() {
    SetConsoleTitleA("Hacknet Tutorial");
    string yn;
    string cmd;
    system("cls");
    Sleep(2000);
    cout << "-----正在初始化FailSafe模式-----\n" << endl;
    Sleep(3000);
    cout << "這件事不對勁...比我想像中的還要複雜...\n";
    Sleep(3000);
    cout << "對了 忘了自我介紹 我的名子叫GigaByte 當你看到這則訊息時 代表我已經死了...\n" << endl;
    Sleep(3000);
    cout << "...";
    Sleep(3000);
    system("cls");
    PlaySound(NULL, NULL, 0);
    PlaySound(TEXT("sounds\\tutorial.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Sleep(1000);
    while(true) {
        system("cls");
        cout << "Tutorial Mode\n"
              << endl
              << "你現在處於危險之中!\n"
              << "請用最快的速度完成教學!\n"
              << "如果準備好了請輸入y 要跳過教學請輸入skip\n"
              << endl;
        cout << "choose: ";
        cin >> yn;
        if (yn=="y") {
            while(true) {
                system("cls");
                cout << "Tutorial Mode\n"
                      << endl
                      << "入侵他人終端裝置將會違反中華民國刑法第358條\n"
                      << "從現在開始 為自己的行為負責吧!\n"
                      << "如果準備好了請輸入y繼續\n"
                      << endl;
                cout << "choose: ";
                cin >> yn;
                if (yn=="y") {
                    system("cls");
                    cout << "正在與D3f4ult's PC建立安全連線..." << endl;
                    Sleep(2000);
                    cout << "已連接" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 你好 我是Bit的助手 現在請跟者我一步一步操作 操作完你就學會了...三分之一" << endl;
                    Sleep(1000);
                    cout << "[D3f4ult] 首先 在下面輸入mysvr" << endl;
                    while(true) {
                        cout << "[root] ~$ ";
                        getline(cin, cmd);
                        if (cmd=="mysvr") {
                            cout << "正在連接到我的伺服器..." << endl;
                            Sleep(2000);
                            cout << "完成" << endl;
                            cout << "\n";
                            break;
                        } else {
                            cout << "指令錯誤!" << endl;
                            cout << "\n";
                            cout << "[D3f4ult] 如果遇到這種情況 你需要再輸入一次指令 或者輸入help尋求幫助" << endl;
                        }
                    }
                    cout << "[D3f4ult] 看到這個代表連線成功" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 如果看到這個代表連線失敗" << endl;
                    cout << "\n";
                    cout << "正在連接到我的伺服器..." << endl;
                    cout << "已失去連線!" << endl;
                    cout << "\n";
                    Sleep(2000);
                    cout << "[D3f4ult] 需要重新連線一次" << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] 但是大部分的情況都是連線成功" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 接下來輸入scan" << endl;
                    while(true) {
                        cout << "[myserver] ~$ ";
                        getline(cin, cmd);
                        if (cmd=="scan") {
                            cout << "以下是目前在區網上找的到的電腦or伺服器\n"
                                 << "1. Jhon's Server (192.168.45.2)\n"
                                 << "2. Hoyiqiang's NAS (192.168.31.4)\n"
                                 << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] 接著輸入cnt 1 cnt就是連線 1就是電腦的編號" << endl;
                    while(true) {
                        cout << "[myserver] $~ ";
                        getline(cin, cmd);
                        if (cmd=="cnt 1") {
                            cout << "正在連接到Jhon's Server..." << endl;
                            cout << "完成" << endl;
                            Sleep(1000);
                            cout << "\n";
                            break;
                        }
                    }
                    cout << "[D3f4ult] 接者輸入info" << endl;
                    while(true) {
                        cout << "[John's Server] $~ ";
                        getline(cin, cmd);
                        if (cmd=="info") {
                            cout << endl
                                << "Server Info\n"
                                << endl
                                << "server IP:192.168.45.2\n";
                            Sleep(2000);
                            cout << "server files:(Unknown)" << endl;
                            Sleep(2000);
                            cout << "ping:103ms" << endl;
                            Sleep(2000);
                            break;
                        }
                    }
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("sounds\\tutorial2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    cout << endl
                         << "\"◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥\n"
                         << "\"  |_ _| \\| |/ __/ _ \\|  \\/  |_ _| \\| |/ __|  / __/ _ \\| \\| | \\| | __/ __|_   _|_ _/ _ \\| \\| |\n"
                         << "\"   | || .` | (_| (_) | |\\/| || || .` | (_ | | (_| (_) | .` | .` | _| (__  | |  | | (_) | .` |\n"
                         << "\"  |___|_|\\_|\\___\\___/|_|  |_|___|_|\\_|\\___|  \\___\\___/|_|\\_|_|\\_|___\\___| |_| |___\\___/|_|\\_|\n"
                         << "\"◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥\n"
                         << endl;
                    cout << "[D3f4ult] 好吧...看來這個伺服器的基本資料不讓我們看 我們只好強制fu,4fm3y xul4x了..." << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] what??? yp3ak7回事??? 我的文y4怎麼1u04t/6亂碼了???" << endl;
                    Sleep(2000);
                    cout << "[hacker]: 哈哈哈!!! 你的電腦已經被我掌控了!!!" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 怎麼...huiogrbeijpa 回事..." << endl;
                    Sleep(3000);
                    cout << "[hacker]: 跟你自我介紹一下 我叫大明 我是熱愛電腦的玩家 也喜歡玩電腦 而現在的情況就是我搞的 哈哈哈哈!!!" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 你為gp6ak7...要這u;4做???" << endl;
                    Sleep(2000);
                    cout << "[hacker]: 因為我想考驗你的隨機應變能力啊awa" << endl;
                    Sleep(3000);
                    cout << "[D3f4ult] 既然5k4u;4...那就ao6辦法了... 快! 用別的方法解決這次的危機!" << endl;
                    cout << "(回到你的電腦 檢查log 看看他的連線蹤跡)" << endl;
                    while(true) {
                        cout << "[Jhon's Server] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="mysvr") {
                            break;
                        }
                    }
                    while(true) {
                        cout << "[myserver] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="ls") {
                            cout << "home\n"
                                 << "log\n"
                                 << "bin\n"
                                 << "sys\n";
                        } else if (cmd=="cd log") {
                            cout << "[hacker] shell bypassed\n"
                                 << "[hacker] firewall solved\n"
                                 << "[hacker] OPEN PORT:22\n"
                                 << "[hacker] OPEN PORT:25\n"
                                 << "[hacker] OPEN PORT:21\n"
                                 << "[hacker] OPEN PORT:80\n";
                            break;
                        } else if (cmd=="cd bin") {
                            cout << "-Empty-" << endl;
                        } else if (cmd=="cd sys") {
                            cout << "x-server.sys\n"
                                 << "os-config.sys\n"
                                 << "bootcfg.dll\n"
                                 << "netcfgx.dll\n";
                        }
                    }
                    cout << "[D3f4ult] 好了! 接著scan 查查看現在hacker的編號是多少!" << endl;
                    while(true) {
                        cout << "[mysvr] ~$ C:/";
                        getline(cin, cmd);
                        if (cmd=="scan") {
                            break;
                        }
                    }
                    cout << "以下是目前在區網上找的到的電腦or伺服器\n"
                          << "1. Jhon's Server (192.168.45.2)\n"
                          << "2. Hoyiqiang's NAS (192.168.31.4)\n"
                          << "3. huirohbuhrupieahiui (666.666.666.666)\n"
                          << endl;
                    Sleep(2000);
                    cout << "echo [D3f4ult] 接者cnt 3" << endl;
                    while(true) {
                        cout << "[myserver] $~ ";
                        getline(cin, cmd);
                        if (cmd=="cnt 3") {
                            break;
                        }
                    }
                    cout << "echo [D3f4ult] 好! 現在輸入porthack駭入他的電腦!" << endl;
                    while(true) {
                        cout << "[huirohbuhrupieahiui] $~ ";
                        getline(cin, cmd);
                        if (cmd=="porthack") {
                            cout << "{PortHack} running..." << endl;
                            PortHack();
                            Sleep(2000);
                            cout << "[D3f4ult] 快啊...已經dj94來不及了!" << endl;
                            Sleep(5000);
                            cout << "{PortHack} done!" << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] 很好! 現在輸入rm *刪除電腦gl4的所有資料 (不是你的電腦)" << endl;
                    while(true) {
                        cout << "[huirohbuhrupieahiui] $~ C:/";
                        getline(cin, cmd);
                        if (cmd=="rm *") {
                            cout << "deleting..." << endl;
                            Sleep(3000);
                            cout << "done!" << endl;
                            break;
                        }
                    }
                    cout << "[D3f4ult] 非常好 終於完成了!" << endl;
                    Sleep(2000);
                    cout << "[hacker]: 可惡...你的njo6ru 應變能力怎麼dk3u3這麼強???" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 哈哈哈 現在你變成亂碼了!" << endl;
                    Sleep(2000);
                    cout << endl
                         << "\"◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥\n"
                         << "\"  |_ _| \\| |/ __/ _ \\|  \\/  |_ _| \\| |/ __|  / __/ _ \\| \\| | \\| | __/ __|_   _|_ _/ _ \\| \\| |\n"
                         << "\"   | || .` | (_| (_) | |\\/| || || .` | (_ | | (_| (_) | .` | .` | _| (__  | |  | | (_) | .` |\n"
                         << "\"  |___|_|\\_|\\___\\___/|_|  |_|___|_|\\_|\\___|  \\___\\___/|_|\\_|_|\\_|___\\___| |_| |___\\___/|_|\\_|\n"
                         << "\"◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥◣◥\n"
                         << endl;
                    cout << "[未知的連線]: 全部都給我閉嘴" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 你是誰???" << endl;
                    Sleep(2000);
                    cout << "[未知的連線]: 我是這個遊戲的創造者:阿強" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 不是啊 你混進來幹嘛???" << endl;
                    Sleep(2000);
                    cout << "[未知的連線]: 我要告訴你們兩個 我在你們的電腦裡放了兩個forkbomb" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] what?????" << endl;
                    Sleep(2000);
                    cout << "[hacker]: what??????????????" << endl;
                    Sleep(2000);
                    cout << "[未知的連線]: 過了5秒後 這個forkbomb就會爆炸 你電腦上的所有資料都會不見" << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 你為什麼要這樣做???" << endl;
                    Sleep(2000);
                    cout << "[未知的連線]: 因為我想不到劇情的結尾了 ._." << endl;
                    Sleep(2000);
                    cout << "[D3f4ult] 唉呦我*!!!!!!!!!!" << endl;
                    Sleep(1000);
                    cout << "[hacker]: what the f***" << endl;
                    Sleep(1000);
                    cout << "(程序已被強制停止)" << endl;
                    Sleep(1000);
                    cout << "[hacker]: (已中斷連線)" << endl;
                    Sleep(1000);
                    cout << "[未知的連線]: 就這樣! 上傳!" << endl;
                    Sleep(2000);
                    system("cls");
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("sounds\\DreamHead.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    cout << "Demo (兼具教學) 就到這裡結束了 後面我會繼續發更新\n"
                          << "感謝各位遊玩試玩版!\n"
                          << endl;
                    string homes;
                    while(true) {
                        cout << "回到主選單(home) 離開(exit) :";
                        cin >> homes;
                        if (homes=="home") {
                            break;
                        } else if (homes=="exit"){
                            string chse="2\n";
                            break;
                        }
                    }
                    return;
                } else if (yn=="n") {
                    Cmd();
                    break;
                }
            }
        } else if (yn=="skip") {
            Cmd();
            break;
        }
    }
}