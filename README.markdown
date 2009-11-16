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