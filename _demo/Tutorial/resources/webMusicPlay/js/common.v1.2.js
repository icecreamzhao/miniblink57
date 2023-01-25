$(function(){

    /*搜索*/
    function search()
    {
        var keyword = $(".header-search-input").val();

        var plate_path = $(".header-search-input").attr("data-path");

        if(keyword == "")
        {
            return false;
        }else{

            $.post("/index.php?m=Search&a=checkWord&ajax=1",{"keyword":keyword,"plate_path":plate_path},function(data){

                if(data.status == 200)
                {
                    location.href=data.url;

                }else if(data.status == 404){

                    location.href="/searchword"+search_M+"/"+encodeURI(keyword)+".html";

                }else if(data.status == 500){

                    location.href="/";
                }
            },"json")


        }
    }

    $(".search-button").click(function(){ search();});
    $(".header-search-input").keydown(function(event){if (event.which == 13) { search(); }});
	
	
	$("img.lazyload").lazyload({effect: "show",threshold :100});


});


window.onload = function(){

    statsData.loadTime = ((new Date()).getTime()-statsData.startLoadTime)/1000;
    $.ajax({
        type:'get',
        url:'/index.php?m=pageCount&ajax=1',
        data:{pageCode:statsData.pageCode,exeTime:statsData.exeTime,loadTime:statsData.loadTime,url:statsData.url,s_s:statsData.s_s,s_k_i:statsData.s_k_i},
        dataType : 'jsonp',
        jsonp:"jsoncallback",
        success  : function() {
        },
        error : function() {
        }
    });
	
	var _hmt = _hmt || [];
	(function() {
	  var hm = document.createElement("script");
	  hm.src = "https://hm.baidu.com/hm.js?eb0a4fc1241ae3ed223b75a4d22c75c0";
	  var s = document.getElementsByTagName("script")[0]; 
	  s.parentNode.insertBefore(hm, s);
	})();
	

}