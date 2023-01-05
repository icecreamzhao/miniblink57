# 简介
miniblink是基于chromium的浏览器控件，也可以用来开发软件（类似于electron），更多信息请见官网http://miniblink.net 

而blinkUI是基于blink的UI界面库，只保留UI相关的代码，去掉了浏览器的功能，单纯只用来开发UI界面
用web(js+HTML+CSS)写界面，C++写逻辑。既有web的开发效率，又有C++的运行速度

由于blink耦合性太高、而且无关UI的代码太多，所以我选择从miniblink去裁剪和提取UI代码，并且去掉了nodejs，改用C++来开发逻辑，这样才能有C++的运行速度

此项目暂时只用作技术研究，只花1~2周的时间裁剪和改动，所以会有很多细节和bug没有去完善，等工作上的事情搞顺后，再来继续开源项目


# 特性 
- 极致小巧的体积，只有几M
- 跨PC平台
- C++、C#、QT、MFC、Delphi等语言框架都可以相互结合，把开发风险降为0（如果此界面库实现不了的功能，就可以用原生库实现）
- 支持Windows XP、NPAPI
- 支持HTML5，对各种前端库友好，比如vue等
- 支持TypeScript


# 未来计划的特性 
- 跨移动端平台


# 技术选型：为什么用web、C++的方式来写界面？
## 1、理由简介：
- 业务逻辑跟界面分离：
js脚本做界面、c++做逻辑。改动界面不会影响逻辑，大大减少了bug率、提升了维护效率

- 性能：
electron用nodejs写业务逻辑，性能比C++要差很多，所以业务逻辑还是用C++去写
而web只做界面，就对性能没影响（一秒达到60帧即可，肉眼看不出区别）
如果界面代码影响到了性能，那肯定是代码设计有问题，因为就算是20年前的古董机做到一秒60帧也没问题（普通软件不是游戏，动画很少，不需要那么高性能）

- 高效、快速开发：
js脚本的开发效率比C++要快很多，少写很多代码。
而且界面的改动非常频繁，放到脚本里跟逻辑分离，不仅可以减少bug率，而且不用编译就可以

- web的界面功能最强大、最完整：
web界面的底层设计理念，跟普通的DirectUI完全不一样，能够非常快速的实现各种炫酷、变态的界面需求
不仅代码量少几十倍，而且不需要开发者懂界面原理。

## 2、开发效率差好几倍、甚至几十倍：
比如想实现动画功能，MFC要自己去写动画逻辑，简单动画要写几百行，复杂动画要写几千行，而且还很难通用。
而web实现同样的动画，只要几行代码，最多几十行代码。代码量少了【100倍】，开发速度自然也快了100倍。

而MFC自绘button，知名的开源库ButtonST也是用了3000多行代码才实现
但是web依然只需要几行代码就能实现这些效果，而且还能实现它做不出来的效果，比如异形按钮、按钮区域外圈发光（它要做出来得5000行、甚至更多）。


## 3、web有最强大的生态支持：
虽然js的效率比不上lua等脚本，html也不如json简洁
但是web有最强大的生态支持，比如：
- 最全的各种文档支持，只要会C++，几小时就能学会大部分语法。遇到新问题，也可以很快搜索解决。
其他自创的界面库，几小时还没摸清门道呢，遇到新问题，也只能去看源码、甚至调试源码去解决。

- 虽然其他界面库，也能实现web的所有功能，但是最强大、最靠谱的就只有web。
比如QT的QML、HTMLayout、金山的kdgui等等，都自创了一套语法和体系，
但依然有很多bug、或者暗坑、或者不够方便、文档不足、遇到新问题很难解决，得自己去调试界面库代码。

- web开源贡献者超级多


## 4、对开发者的经验要求低：
MFC、VC++，至少需要3年界面开发经验（QT也需要1~3年经验），才能快速实现各种复杂、炫酷的界面。
比如想实现炫酷的button按钮，得调用底层API去自绘，需要懂界面原理（比如消息机制、GDI绘制等等），
特别是消息机制最复杂，没有3年界面经验，基本上是研究不透的。
即使有开源库可以用，但依然这些开源库依然不够强大，遇到更复杂的界面，依然得自己去自绘、去了解界面原理。

而web，只需要一个**普通应届生**就能实现这些功能。
因为web不需要了解底层的消息机制、不需要自绘，就可以随意组合拼装界面，实现所有复杂的、炫酷的界面，包括动画也是几行代码就实现了。

web**好招人**、而且工资也低
现在已经没几个人会windows开发了，甚至会C++的都少了很多，人才已经断层断代了。
但是web程序员一抓一大把，应届生也可以快速上手。


## 5、其他优势：
- 自动化测试，大部分框架只能自动化测试逻辑，但是web还可以自动化测试界面（其他的虽然也可以实现，但需要自己去开发基础库）
- 动态调试、改动界面等，还有一堆web的好处，就不一一举例了。


## 6、简单总结，就是：
C++要花【1个月】才能开发完的，web最多【1周】就能搞定，甚至有些一两天就能搞定（因为有非常多现成的开源库）
一般写小工具对性能没要求的，我都是用js、或者python搞定

界面越复杂、越炫酷，需求越变态，就越能体现web功能的强大、以及开发效率的优势

# 其他界面库的历史教训
## 1、腾讯的GF界面库
就基本只剩下QQ部门在用了，连微信部门都不用。
当时花了几千万成本，一年时间搞出来的，也推广到了全公司，但是由于文档教程很少，不太懂界面的人遇到问题就很难快速搞定，
以及易用性不如后来的duilib，加上界面库的开发者基本上升职或者离开了，几乎没有人继续维护和推广，因此就没落了。

我遇到bug时，好几次都要自己调试到界面库内核代码去找原因，找到了原因还不能轻易修改，因为影响面太广，一般都是采取绕过bug的方式去实现功能。
但是大部分人对界面是不太懂的，遇到问题是不能快速解决的，因此没落也是必然的。

## 2、金山的贝壳库bkwin、kdgui
是由于金山项目少，所以金山毒霸一直在用。但是WPS就是用QT、而金山网盘也是用duilib。
金山还有一个界面库叫**kdgui**，仅用于毒霸的加速球界面，其实很强大，比腾讯的GF界面库更牛，动画以及各种炫酷界面，都能快速实现，
跟web开发效率有得一拼，而且是C++写逻辑的，运行速度也很快。
而且是用松鼠脚本Squirrel，速度跟lua差不多，但是语法类似C++；没有用xml，而是用json，更简洁。
但由于核心人员离职，以及文档太少，依然没落了。

## 3、迅雷的BOLT界面库
也因为核心人员的离职，慢慢被抛弃了。 迅雷网盘改用duilib、新版迅雷改用electron。

## 4、duilib、SOUI等开源界面库
由于开发人员有限，没有公司支撑，都是半死不活的，有问题都得自己去改界面库，
在没有更好的界面库之前，它们确实是最好的选择

## 5、QT
也因为被卖来卖去，发展很缓慢，
- QWidget 核心理念跟MFC类似，已经过时了，但由于比MFC更完善，有很多现成的框架。如果没有太难的界面需求、或者不会经常改动界面，用着还是不错的。
- QML 核心理念跟web类似，很先进，但是由于bug太多，以及自创了语法，没有web那样完善的生态，所以还是有很多问题，遇到问题还得自己解决。

## 6、flutter等
主要还是移动端比较成熟，但PC端还有很多bug和问题。特别是flutter的奇葩嵌套语法，非常冗余繁琐，不看好这些新型语法，没有经过时间的检验，也没有完善的生态支持，纯属炫技

## 7、总结
以上历史事实都证明：即使是腾讯这种花几千万成本搞出来的界面库，能满足当时几年的需求。但是随着技术的更新、需求的迭代，都会被慢慢淘汰。
**唯有站在巨人的肩膀上**，才能真正长久发展，越来越强大。

现在的软件开发，**已经不是拼功能实现了，而是拼开发效率、维护效率了**。
要说实现功能，用**20多年前**的MFC、甚至直接用VC++ API，都能实现所有功能，所以只要基础功底好，就没有实现不了的功能，比拼这个没有意义。
但是拼开发效率，差别就太大了：
- MFC自绘按钮要做的完善一点，需要【3000行】代码，而且需要资深界面开发人员才能搞定；
而web【几行】代码就能实现同样的功能，并且只需要应届生就能搞定，根本不需要自绘，也不需要了解各种界面原理。
QT的设计理念跟MFC很相似，估计自绘按钮也是需要几百行到几千行代码，至少所有的东西都得自己调用API去绘制，不能几行代码搞定。

- MFC做一个炫酷的界面，1个人需要开发3 ~ 6个月（指大项目，不是指小工具）； web只需要1 ~ 2周。  QT、duilib也需要1个月左右。

拼维护效率：
- MFC、QT到处都是界面跟逻辑耦合，改界面的时候，基本上会改动或者移动逻辑代码，存在bug风险。duilib好一点，但也很耦合。
web就没这个问题，可以大改版界面，然后逻辑代码完全不用改动（前提是代码设计合理），甚至都不需要重新编译。

如果不选择web，不站在巨人的肩膀上，那么在生态、文档等方面，都会慢慢淘汰、没落，最后只剩下少数界面功底强的人在用，其他人都会选择其他更易用的界面库。
flutter等界面库虽然是巨头开发的，但还太年轻，没有像web这样**经过几十年的考验**，选型风险和代价还是很大的。毕竟谷歌、微软抛弃和做死的项目也很多。


# 联系方式
Q群956223415


# 致谢
特别感谢好基友weolar，他是miniblink、kdgui的作者

我在金山毒霸的时候，给他打过一段时间的辅助，给kdgui写了一套更方便更强大的控件库，把开发效率提高了4倍

（之前开发一个完整的项目需要1个月，使用了控件库之后只需要1周）

现在继续给他打辅助，把miniblink的UI部分提取出来
