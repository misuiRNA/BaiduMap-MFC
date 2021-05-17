### <center>MFC集成百度地图API方法</center>

**工具**：VS2015（或VS2012，demo是使用VS2012写的）

**语言**：C++、HTML、JavaScript

**平台**：百度地图API、高德地图API

**实现方式**：有两种方式可以实现均采用MFC应用程序实现

1. 新建基于对话框的MFC应用，使用HTML对话框；（该实现方式支持高德地图，不支持百度地图）
2. 新建基于对话框的MFC应用，使用普通对话框，添加web browser控件显示地图（**推荐使用：**该实现方式同时支持高德地图、百度地图，且相对较第一种方式实现起来更容易控制）

**实现步骤**：（采用第二种实现方式）

1. 新建基于对话框的MFC应用；

2. 添加Web Browser控件（右键—>插入Active X控件—>Microsoft Web Browser）；

3. 设置控件属性、添加控件变量（例如变量名为browser）；

4. 编写HTML文件，引导、展示地图（可参考百度地图API或高德地图API开发文档）；

5. 为browser设置页面，设置方式如下：

   ```c++
   browser.Navigate(_T("file:///C:file/test.html"),NULL,NULL,NULL,NULL);
   ```

6. 编写JavaScript文件，实现与地图相关的业务代码；

7. C++代码与JS代码相互调用，实现功能。

**主要技术**：

&emsp;&emsp;地图功能其实是调用了百度地图、高德地图或谷歌地图等平台的JavaScript API接口，通过JS代码实现地图有关业务，再使用C++与JS交互的接口方法，使C++代码与JS代码相互调用，完成该部分功能。

1. **百度地图API**（http://lbsyun.baidu.com/）；

2. **JavaScript**；

3. **C++调取JavaScript函数的接口方法**（WebPage类）；

   1. 将webpage源码导入工程，并在对应头文件中添加声明

   2. 使用示例代码

      ```c++
      CWebPage web;
      web.SetDocument(browser.get_Document());
      web.CallJScript(jsFuncName, NULL, NULL, &varResult);
      ```
      
      > 参考链接：
      >
      > https://blog.csdn.net/tangyin025/article/details/8274519
>
      > https://blog.csdn.net/zt_xcyk/article/details/79729532
   
4. **JavaScript调用C++函数的方法**（主要用于点击地图获取对应坐标值）

   &emsp;&emsp;使用IDispatch接口作为该部分的主要技术支撑，项目中以轻量的方式使用IDispatch技术，若需要实现功能较为复杂或可维护性高的代码，需要围绕IDispatch对代码进行重构。

   当前工程对IDispatch进行了封装，外部代码直接使用JavaScriptAdapter即可。实例化JavaScriptAdapter并注册需要被JavaScript调用的cpp函数即可在js代码中调用cpp函数。

   > 参考链接：
   >
   > https://www.cnblogs.com/wgwyanfs/p/7230657.html
