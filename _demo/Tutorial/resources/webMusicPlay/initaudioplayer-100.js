jQuery(document).ready(function(){
    var scripts = document.getElementsByTagName("script");
    var jsFolder = "";
    for (var i= 0; i< scripts.length; i++)
    {
        if( scripts[i].src && scripts[i].src.match(/initaudioplayer-100\.js/i))
            jsFolder = scripts[i].src.substr(0, scripts[i].src.lastIndexOf("/") + 1);
    }
    jQuery("#amazingaudioplayer-100").amazingaudioplayer({
        jsfolder:jsFolder,
        skinsfoldername:"",
        tracklistarrowimage:"tracklistarrow-48-16-0.png",
        timeformatlive:"%CURRENT% / LIVE",
        volumeimagewidth:24,
        barbackgroundimage:"",
        tracklistarrowimageheight:16,
        showtime:true,
        titleinbarwidth:80,
        showprogress:true,
        random:false,
        titleformat:"%TITLE%",
        height:600,
        loopimage:"loop-24-24-0.png",
        prevnextimage:"prevnext-48-48-1.png",
        showinfo:false,
        imageheight:100,
        skin:"BarWithPlaylist",
        responsive:true,
        loopimagewidth:24,
        showstop:true,
        prevnextimageheight:48,
        infoformat:"By %ARTIST% %ALBUM%<br />%INFO%",
        tracklistbackgroundimage:"",
        showloading:false,
        forcefirefoxflash:false,
        tracklistscroll:true,
        preloadaudio:true,
        showvolumebar:true,
        imagefullwidth:false,
        width:500,
        showimage:false,
        showloop:true,
        volumeimage:"volume-24-24-0.png",
        playpauseimagewidth:48,
        loopimageheight:24,
        tracklistitemformat:"<div class='amazingaudioplayer-item-id'>%ID%</div><div class='amazingaudioplayer-item-info'>%DURATION%</div><div class='amazingaudioplayer-item-title'>%TITLE%</div>",
        prevnextimagewidth:48,
        titleinbarwidthmode:"fixed",
        forceflash:false,
        tracklistarrowimagewidth:48,
        playpauseimageheight:48,
        showbackgroundimage:false,
        stopimage:"stop-48-48-1.png",
        showvolume:true,
        playpauseimage:"playpause-48-48-1.png",
        forcehtml5:false,
        showprevnext:true,
        backgroundimage:"",
        loadingformat:"Loading...",
        progressheight:32,
        showtracklistbackgroundimage:false,
        titleinbarscroll:true,
        showtitle:false,
        defaultvolume:100,
        showtitleinbar:false,
        heightmode:"auto",
        titleinbarformat:"%TITLE%",
        showtracklist:true,
        stopimageheight:48,
        volumeimageheight:24,
        stopimagewidth:48,
        volumebarheight:80,
        noncontinous:false,
        stopotherplayers:true,
        showbarbackgroundimage:false,
        volumebarpadding:8,
        imagewidth:100,
        timeformat:"%CURRENT% / %DURATION%",
        autoplay:true,
        fullwidth:false,
        loop:1,
        tracklistitem:10
    });
});