R3versi
=======

*A Terminal Reversi Game*


Outline
-------

This is a Reversi Game that I wrote in my first year of college life.  It's a newbie's work, and the code is in a mass, which is lack of comments.

I'm not going to have any modification on this project; I just want to push this to the Internet.

Just fork this if you want to improve this game.

How to play
-----------

In this game, the black side is displayed in red and the white side is in white.  There is no Computer AI; black and white sides should play on a single machine in turns.

Controllers are:

* Arrow Key or HJKL: control the position of cursor
* Space: Put

How to build
------------

You need curses library, which is a bulit-in lib in Unix-like OS.  Just type `make' to build the game.

An extension of [Dev-C++](http://www.bloodshed.net/devcpp.html) named [PDcurses](http://pdcurses.sourceforge.net/) is available via Dev-C++'s package manager.  If you want to build it in Win32, just install pdcurses package in Dev-C++, open the reversi.dev with Dev-C++, and hit "Build."

## How to install PDcurses Package in Dev-C++

 1. Visit [this page](http://sourceforge.net/projects/devpaks/files/pdcurses/) and download the latest version of pdcurses-XXXXXX.DevPak
 2. Launch Package Manager, which might be located in [Start] / [All Programs] / [Bloodshed Dev-C++] / [Package Manager]. You can also double click the executable file C:\Dev-Cpp\Packman.exe
 3. Hit [Install] at the top-left corner of Package Manager window.
 4. Point to the pdcurses-XXXXXX.DevPak file that you've just downloaded and click "Open" button.
 5. Click [Next] and [Finish] buttons until wizard closes.

Known Issue
-----------

 1. When the player can't play any step, the game ends immediately.  However in the common rule, in this situation, it will become the turn of the opposite player.

--

中文說明
====

*一個在終端機玩的黑白棋遊戲*

簡介
----

這是我在大一寫的黑白棋遊戲，但寫得很雜亂就是了，甚至還沒寫註解(囧)。

這個專案不會有任何的新修訂，我只是想把它放到網路上。

如果你想要改就直接 fork 吧！

怎麼玩
---

黑棋是顯示成紅色的，白棋就白色。沒有人工智慧程式，黑白兩造必須在同一台機器上輪流玩。

如何控制：

* 方向鍵或 HJKL：移動游標位置
* 空白鍵：放子

怎麼編譯
----

你要有 curses 的函式庫，這在 Unix-like 作業系統是內建的。打 make 就可以編譯了。

當然 [Dev-C++](http://www.bloodshed.net/devcpp.html) 也有名叫 [PDcurses](http://pdcurses.sourceforge.net/)  的函式庫可以用，用套件管理器就可以安裝了。如果你要用 Dev-C++ 編譯的話，請先安裝 PDcurses 函式庫，接著開啟 reversi.dev 的專案檔，按下「編譯」就好了。

## 用於 Dev-C++ 的 PDcurses Package 安裝方法

 1. 至 [這裡](http://sourceforge.net/projects/devpaks/files/pdcurses/) 下載最新版本的 pdcurses-XXXXXX.DevPak。
 2. 開啟 Package Manager，在 [開始] → [所有程式] → [Bloodshed Dev-C++] → [Package Manager] ，或直接開 C:\Dev-Cpp\Packman.exe
 3. 按下 Package Manager 左上角的 [Install] 按鈕
 4. 在開啟檔案的對話方塊中，選擇剛剛下載的 pdcurses-XXXXXX.DevPak
 5. 一直按 Next 和 Finish 就裝好了。

已知問題
-------

 1. 當一方無法下子的時候，整個遊戲會直接結束到計算分數的地方。但事實上在一般的規則裡，應該是輪到對方下子。