/*
 * Copyright 2011-2012 WebDriver committers
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* AUTO GENERATED - DO NOT EDIT BY HAND */
#ifndef WEBDRIVER_SIZZLE_H_
#define WEBDRIVER_SIZZLE_H_

#include <stddef.h> // For wchar_t.
#include <string> // For std::(w)string.

namespace webdriver {
namespace atoms {

const wchar_t* const SIZZLE[] = { L"(function(){function y(a,b,c,d,f,e){for(var f=0,h=d.length;f<h;f++){va",
    L"r g=d[f];if(g){for(var i=!1,g=g[a];g;){if(g.sizcache===c){i=d[g.sizset", L"];break}if(g.nodeType===1&&!e)g.sizcache=c,g.sizset=f;if(g.nodeName.to",
    L"LowerCase()===b){i=g;break}g=g[a]}d[f]=i}}}function z(a,b,c,d,f,e){for", L"(var f=0,h=d.length;f<h;f++){var g=d[f];if(g){for(var j=!1,g=g[a];g;){",
    L"if(g.sizcache===c){j=d[g.sizset];break}if(g.nodeType===1){if(!e)g.sizc", L"ache=c,g.sizset=f;if(typeof b!==\"string\"){if(g===b){j=!0;break}}else",
    L" if(i.filter(b,\n[g]).length>0){j=g;break}}g=g[a]}d[f]=j}}}var w=/((?:", L"\\((?:\\([^()]+\\)|[^()]+)+\\)|\\[(?:\\[[^\\[\\]]*\\]|['\"][^'\"]*['\"",
    L"]|[^\\[\\]'\"]+)+\\]|\\\\.|[^ >+~,(\\[\\\\]+)+|[>+~])(\\s*,\\s*)?((?:.", L"|\\r|\\n)*)/g,x=0,A=Object.prototype.toString,t=!1,B=!0,p=/\\\\/g,u=/",
    L"\\W/;[0,0].sort(function(){B=!1;return 0});var i=function(a,b,c,d){var", L" c=c||[],f=b=b||document;if(b.nodeType!==1&&b.nodeType!==9)return[];if",
    L"(!a||typeof a!==\"string\")return c;var e,h,g,l,s,m=!0,n=i.isXML(b),k=", L"[],p=a;do if(w.exec(\"\"),e=w.exec(p))if(p=e[3],k.push(e[1]),\ne[2]){l",
    L"=e[3];break}while(e);if(k.length>1&&D.exec(a))if(k.length===2&&j.relat", L"ive[k[0]])h=C(k[0]+k[1],b);else for(h=j.relative[k[0]]?[b]:i(k.shift()",
    L",b);k.length;)a=k.shift(),j.relative[a]&&(a+=k.shift()),h=C(a,h);else ", L"if(!d&&k.length>1&&b.nodeType===9&&!n&&j.match.ID.test(k[0])&&!j.match",
    L".ID.test(k[k.length-1])&&(e=i.find(k.shift(),b,n),b=e.expr?i.filter(e.", L"expr,e.set)[0]:e.set[0]),b){e=d?{expr:k.pop(),set:o(d)}:i.find(k.pop()",
    L",k.length===1&&(k[0]===\"~\"||k[0]===\"+\")&&b.parentNode?b.parentNode", L":b,n);h=\ne.expr?i.filter(e.expr,e.set):e.set;for(k.length>0?g=o(h):m=",
    L"!1;k.length;)e=s=k.pop(),j.relative[s]?e=k.pop():s=\"\",e==null&&(e=b)", L",j.relative[s](g,e,n)}else g=[];g||(g=h);g||i.error(s||a);if(A.call(g)",
    L"===\"[object Array]\")if(m)if(b&&b.nodeType===1)for(a=0;g[a]!=null;a++", L")g[a]&&(g[a]===!0||g[a].nodeType===1&&i.contains(b,g[a]))&&c.push(h[a]",
    L");else for(a=0;g[a]!=null;a++)g[a]&&g[a].nodeType===1&&c.push(h[a]);el", L"se c.push.apply(c,g);else o(g,c);l&&(i(l,f,c,d),i.uniqueSort(c));retur",
    L"n c};i.uniqueSort=function(a){if(v&&\n(t=B,a.sort(v),t))for(var b=1;b<", L"a.length;b++)a[b]===a[b-1]&&a.splice(b--,1);return a};i.matches=functi",
    L"on(a,b){return i(a,null,null,b)};i.matchesSelector=function(a,b){retur", L"n i(b,null,null,[a]).length>0};i.find=function(a,b,c){var d;if(!a)retu",
    L"rn[];for(var f=0,e=j.order.length;f<e;f++){var h,g=j.order[f];if(h=j.l", L"eftMatch[g].exec(a)){var i=h[1];h.splice(1,1);if(i.substr(i.length-1)!",
    L"==\"\\\\\"&&(h[1]=(h[1]||\"\").replace(p,\"\"),d=j.find[g](h,b,c),d!=n", L"ull)){a=a.replace(j.match[g],\"\");break}}}d||(d=typeof b.getElementsB",
    L"yTagName!==\n\"undefined\"?b.getElementsByTagName(\"*\"):[]);return{se", L"t:d,expr:a}};i.filter=function(a,b,c,d){for(var f,e,h=a,g=[],l=b,o=b&&",
    L"b[0]&&i.isXML(b[0]);a&&b.length;){for(var m in j.filter)if((f=j.leftMa", L"tch[m].exec(a))!=null&&f[2]){var n,k,p=j.filter[m];k=f[1];e=!1;f.splic",
    L"e(1,1);if(k.substr(k.length-1)!==\"\\\\\"){l===g&&(g=[]);if(j.preFilte", L"r[m])if(f=j.preFilter[m](f,l,c,g,d,o)){if(f===!0)continue}else e=n=!0;",
    L"if(f)for(var q=0;(k=l[q])!=null;q++)if(k){n=p(k,f,q,l);var r=d^!!n;c&&", L"n!=null?r?e=!0:l[q]=!1:r&&(g.push(k),\ne=!0)}if(n!==void 0){c||(l=g);a",
    L"=a.replace(j.match[m],\"\");if(!e)return[];break}}}if(a===h)if(e==null", L")i.error(a);else break;h=a}return l};i.error=function(a){throw\"Syntax",
    L" error, unrecognized expression: \"+a;};var j=i.selectors={order:[\"ID", L"\",\"NAME\",\"TAG\"],match:{ID:/#((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)/",
    L",CLASS:/\\.((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)/,NAME:/\\[name=['\"]*(", L"(?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)['\"]*\\]/,ATTR:/\\[\\s*((?:[\\w\\u",
    L"00c0-\\uFFFF\\-]|\\\\.)+)\\s*(?:(\\S?=)\\s*(?:(['\"])(.*?)\\3|(#?(?:[", L"\\w\\u00c0-\\uFFFF\\-]|\\\\.)*)|)|)\\s*\\]/,\nTAG:/^((?:[\\w\\u00c0-",
    L"\\uFFFF\\*\\-]|\\\\.)+)/,CHILD:/:(only|nth|last|first)-child(?:\\(\\s*", L"(even|odd|(?:[+\\-]?\\d+|(?:[+\\-]?\\d*)?n\\s*(?:[+\\-]\\s*\\d+)?))\\s",
    L"*\\))?/,POS:/:(nth|eq|gt|lt|first|last|even|odd)(?:\\((\\d*)\\))?(?=[^", L"\\-]|$)/,PSEUDO:/:((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)(?:\\((['\"]?)((",
    L"?:\\([^\\)]+\\)|[^\\(\\)]*)+)\\2\\))?/},leftMatch:{},attrMap:{\"class", L"\":\"className\",\"for\":\"htmlFor\"},attrHandle:{href:function(a){ret",
    L"urn a.getAttribute(\"href\")},type:function(a){return a.getAttribute(", L"\"type\")}},relative:{\"+\":function(a,b){var c=\ntypeof b===\"string",
    L"\",d=c&&!u.test(b),c=c&&!d;d&&(b=b.toLowerCase());for(var d=0,f=a.leng", L"th,e;d<f;d++)if(e=a[d]){for(;(e=e.previousSibling)&&e.nodeType!==1;);a",
    L"[d]=c||e&&e.nodeName.toLowerCase()===b?e||!1:e===b}c&&i.filter(b,a,!0)", L"},\">\":function(a,b){var c,d=typeof b===\"string\",f=0,e=a.length;if(",
    L"d&&!u.test(b))for(b=b.toLowerCase();f<e;f++){if(c=a[f])c=c.parentNode,", L"a[f]=c.nodeName.toLowerCase()===b?c:!1}else{for(;f<e;f++)(c=a[f])&&(a[",
    L"f]=d?c.parentNode:c.parentNode===b);d&&i.filter(b,a,!0)}},\"\":functio", L"n(a,\nb,c){var d,f=x++,e=z;typeof b===\"string\"&&!u.test(b)&&(d=b=b.t",
    L"oLowerCase(),e=y);e(\"parentNode\",b,f,a,d,c)},\"~\":function(a,b,c){v", L"ar d,f=x++,e=z;typeof b===\"string\"&&!u.test(b)&&(d=b=b.toLowerCase()",
    L",e=y);e(\"previousSibling\",b,f,a,d,c)}},find:{ID:function(a,b,c){if(t", L"ypeof b.getElementById!==\"undefined\"&&!c)return(a=b.getElementById(a",
    L"[1]))&&a.parentNode?[a]:[]},NAME:function(a,b){if(typeof b.getElements", L"ByName!==\"undefined\"){for(var c=[],d=b.getElementsByName(a[1]),f=0,e",
    L"=d.length;f<e;f++)d[f].getAttribute(\"name\")===\na[1]&&c.push(d[f]);r", L"eturn c.length===0?null:c}},TAG:function(a,b){if(typeof b.getElementsB",
    L"yTagName!==\"undefined\")return b.getElementsByTagName(a[1])}},preFilt", L"er:{CLASS:function(a,b,c,d,f,e){a=\" \"+a[1].replace(p,\"\")+\" \";if(",
    L"e)return a;for(var e=0,h;(h=b[e])!=null;e++)h&&(f^(h.className&&(\" \"", L"+h.className+\" \").replace(/[\\t\\n\\r]/g,\" \").indexOf(a)>=0)?c||d.",
    L"push(h):c&&(b[e]=!1));return!1},ID:function(a){return a[1].replace(p,", L"\"\")},TAG:function(a){return a[1].replace(p,\"\").toLowerCase()},CHIL",
    L"D:function(a){if(a[1]===\n\"nth\"){a[2]||i.error(a[0]);a[2]=a[2].repla", L"ce(/^\\+|\\s*/g,\"\");var b=/(-?)(\\d*)(?:n([+\\-]?\\d*))?/.exec(a[2]=",
    L"==\"even\"&&\"2n\"||a[2]===\"odd\"&&\"2n+1\"||!/\\D/.test(a[2])&&\"0n+", L"\"+a[2]||a[2]);a[2]=b[1]+(b[2]||1)-0;a[3]=b[3]-0}else a[2]&&i.error(a[",
    L"0]);a[0]=x++;return a},ATTR:function(a,b,c,d,f,e){b=a[1]=a[1].replace(", L"p,\"\");!e&&j.attrMap[b]&&(a[1]=j.attrMap[b]);a[4]=(a[4]||a[5]||\"\").",
    L"replace(p,\"\");a[2]===\"~=\"&&(a[4]=\" \"+a[4]+\" \");return a},PSEUD", L"O:function(a,b,c,d,f){if(a[1]===\"not\")if((w.exec(a[3])||\"\").length",
    L">1||\n/^\\w/.test(a[3]))a[3]=i(a[3],null,null,b);else return a=i.filte", L"r(a[3],b,c,1^f),c||d.push.apply(d,a),!1;else if(j.match.POS.test(a[0])",
    L"||j.match.CHILD.test(a[0]))return!0;return a},POS:function(a){a.unshif", L"t(!0);return a}},filters:{enabled:function(a){return a.disabled===!1&&",
    L"a.type!==\"hidden\"},disabled:function(a){return a.disabled===!0},chec", L"ked:function(a){return a.checked===!0},selected:function(a){return a.s",
    L"elected===!0},parent:function(a){return!!a.firstChild},empty:function(", L"a){return!a.firstChild},\nhas:function(a,b,c){return!!i(c[3],a).length",
    L"},header:function(a){return/h\\d/i.test(a.nodeName)},text:function(a){", L"var b=a.getAttribute(\"type\"),c=a.type;return a.nodeName.toLowerCase(",
    L")===\"input\"&&\"text\"===c&&(b===c||b===null)},radio:function(a){retu", L"rn a.nodeName.toLowerCase()===\"input\"&&\"radio\"===a.type},checkbox:",
    L"function(a){return a.nodeName.toLowerCase()===\"input\"&&\"checkbox\"=", L"==a.type},file:function(a){return a.nodeName.toLowerCase()===\"input\"",
    L"&&\"file\"===a.type},password:function(a){return a.nodeName.toLowerCas", L"e()===\n\"input\"&&\"password\"===a.type},submit:function(a){var b=a.n",
    L"odeName.toLowerCase();return(b===\"input\"||b===\"button\")&&\"submit", L"\"===a.type},image:function(a){return a.nodeName.toLowerCase()===\"inp",
    L"ut\"&&\"image\"===a.type},reset:function(a){var b=a.nodeName.toLowerCa", L"se();return(b===\"input\"||b===\"button\")&&\"reset\"===a.type},button",
    L":function(a){var b=a.nodeName.toLowerCase();return b===\"input\"&&\"bu", L"tton\"===a.type||b===\"button\"},input:function(a){return/input|select",
    L"|textarea|button/i.test(a.nodeName)},focus:function(a){return a===\na.", L"ownerDocument.activeElement}},setFilters:{first:function(a,b){return b",
    L"===0},last:function(a,b,c,d){return b===d.length-1},even:function(a,b)", L"{return b%2===0},odd:function(a,b){return b%2===1},lt:function(a,b,c){",
    L"return b<c[3]-0},gt:function(a,b,c){return b>c[3]-0},nth:function(a,b,", L"c){return c[3]-0===b},eq:function(a,b,c){return c[3]-0===b}},filter:{P",
    L"SEUDO:function(a,b,c,d){var f=b[1],e=j.filters[f];if(e)return e(a,c,b,", L"d);else if(f===\"contains\")return(a.textContent||a.innerText||i.getTe",
    L"xt([a])||\"\").indexOf(b[3])>=\n0;else if(f===\"not\"){b=b[3];c=0;for(", L"d=b.length;c<d;c++)if(b[c]===a)return!1;return!0}else i.error(f)},CHIL",
    L"D:function(a,b){var c=b[1],d=a;switch(c){case \"only\":case \"first\":", L"for(;d=d.previousSibling;)if(d.nodeType===1)return!1;if(c===\"first\")",
    L"return!0;d=a;case \"last\":for(;d=d.nextSibling;)if(d.nodeType===1)ret", L"urn!1;return!0;case \"nth\":var c=b[2],f=b[3];if(c===1&&f===0)return!0",
    L";var e=b[0],h=a.parentNode;if(h&&(h.sizcache!==e||!a.nodeIndex)){for(v", L"ar g=0,d=h.firstChild;d;d=d.nextSibling)if(d.nodeType===\n1)d.nodeInde",
    L"x=++g;h.sizcache=e}d=a.nodeIndex-f;return c===0?d===0:d%c===0&&d/c>=0}", L"},ID:function(a,b){return a.nodeType===1&&a.getAttribute(\"id\")===b},",
    L"TAG:function(a,b){return b===\"*\"&&a.nodeType===1||a.nodeName.toLower", L"Case()===b},CLASS:function(a,b){return(\" \"+(a.className||a.getAttrib",
    L"ute(\"class\"))+\" \").indexOf(b)>-1},ATTR:function(a,b){var c=b[1],c=", L"j.attrHandle[c]?j.attrHandle[c](a):a[c]!=null?a[c]:a.getAttribute(c),d",
    L"=c+\"\",f=b[2],e=b[4];return c==null?f===\"!=\":f===\"=\"?d===e:f===\"", L"*=\"?d.indexOf(e)>=\n0:f===\"~=\"?(\" \"+d+\" \").indexOf(e)>=0:!e?d&&",
    L"c!==!1:f===\"!=\"?d!==e:f===\"^=\"?d.indexOf(e)===0:f===\"$=\"?d.subst", L"r(d.length-e.length)===e:f===\"|=\"?d===e||d.substr(0,e.length+1)===e+",
    L"\"-\":!1},POS:function(a,b,c,d){var f=j.setFilters[b[2]];if(f)return f", L"(a,c,b,d)}}},D=j.match.POS,E=function(a,b){return\"\\\\\"+(b-0+1)},q;f",
    L"or(q in j.match)j.match[q]=RegExp(j.match[q].source+/(?![^\\[]*\\])(?!", L"[^\\(]*\\))/.source),j.leftMatch[q]=RegExp(/(^(?:.|\\r|\\n)*?)/.source",
    L"+j.match[q].source.replace(/\\\\(\\d+)/g,E));var o=function(a,\nb){a=A", L"rray.prototype.slice.call(a,0);if(b)return b.push.apply(b,a),b;return ",
    L"a};try{Array.prototype.slice.call(document.documentElement.childNodes,", L"0)}catch(F){o=function(a,b){var c=0,d=b||[];if(A.call(a)===\"[object A",
    L"rray]\")Array.prototype.push.apply(d,a);else if(typeof a.length===\"nu", L"mber\")for(var f=a.length;c<f;c++)d.push(a[c]);else for(;a[c];c++)d.pu",
    L"sh(a[c]);return d}}var v,r;document.documentElement.compareDocumentPos", L"ition?v=function(a,b){if(a===b)return t=!0,0;if(!a.compareDocumentPosi",
    L"tion||!b.compareDocumentPosition)return a.compareDocumentPosition?\n-1", L":1;return a.compareDocumentPosition(b)&4?-1:1}:(v=function(a,b){if(a==",
    L"=b)return t=!0,0;else if(a.sourceIndex&&b.sourceIndex)return a.sourceI", L"ndex-b.sourceIndex;var c,d,f=[],e=[];c=a.parentNode;d=b.parentNode;var",
    L" h=c;if(c===d)return r(a,b);else if(c){if(!d)return 1}else return-1;fo", L"r(;h;)f.unshift(h),h=h.parentNode;for(h=d;h;)e.unshift(h),h=h.parentNo",
    L"de;c=f.length;d=e.length;for(h=0;h<c&&h<d;h++)if(f[h]!==e[h])return r(", L"f[h],e[h]);return h===c?r(a,e[h],-1):r(f[h],b,1)},r=function(a,b,c){if",
    L"(a===b)return c;\nfor(a=a.nextSibling;a;){if(a===b)return-1;a=a.nextSi", L"bling}return 1});i.getText=function(a){for(var b=\"\",c,d=0;a[d];d++)c",
    L"=a[d],c.nodeType===3||c.nodeType===4?b+=c.nodeValue:c.nodeType!==8&&(b", L"+=i.getText(c.childNodes));return b};(function(){var a=document.create",
    L"Element(\"div\"),b=\"script\"+(new Date).getTime(),c=document.document", L"Element;a.innerHTML=\"<a name='\"+b+\"'/>\";c.insertBefore(a,c.firstCh",
    L"ild);if(document.getElementById(b))j.find.ID=function(a,b,c){if(typeof", L" b.getElementById!==\"undefined\"&&!c)return(b=\nb.getElementById(a[1]",
    L"))?b.id===a[1]||typeof b.getAttributeNode!==\"undefined\"&&b.getAttrib", L"uteNode(\"id\").nodeValue===a[1]?[b]:void 0:[]},j.filter.ID=function(a",
    L",b){var c=typeof a.getAttributeNode!==\"undefined\"&&a.getAttributeNod", L"e(\"id\");return a.nodeType===1&&c&&c.nodeValue===b};c.removeChild(a);",
    L"c=a=null})();(function(){var a=document.createElement(\"div\");a.appen", L"dChild(document.createComment(\"\"));if(a.getElementsByTagName(\"*\").",
    L"length>0)j.find.TAG=function(a,c){var d=c.getElementsByTagName(a[1]);i", L"f(a[1]===\n\"*\"){for(var f=[],e=0;d[e];e++)d[e].nodeType===1&&f.push(",
    L"d[e]);d=f}return d};a.innerHTML=\"<a href='#'></a>\";if(a.firstChild&&", L"typeof a.firstChild.getAttribute!==\"undefined\"&&a.firstChild.getAttr",
    L"ibute(\"href\")!==\"#\")j.attrHandle.href=function(a){return a.getAttr", L"ibute(\"href\",2)};a=null})();document.querySelectorAll&&function(){va",
    L"r a=i,b=document.createElement(\"div\");b.innerHTML=\"<p class='TEST'>", L"</p>\";if(!(b.querySelectorAll&&b.querySelectorAll(\".TEST\").length==",
    L"=0)){i=function(b,c,e,h){c=c||document;if(!h&&\n!i.isXML(c)){var g=/^(", L"\\w+$)|^\\.([\\w\\-]+$)|^#([\\w\\-]+$)/.exec(b);if(g&&(c.nodeType===1|",
    L"|c.nodeType===9))if(g[1])return o(c.getElementsByTagName(b),e);else if", L"(g[2]&&j.find.CLASS&&c.getElementsByClassName)return o(c.getElementsBy",
    L"ClassName(g[2]),e);if(c.nodeType===9){if(b===\"body\"&&c.body)return o", L"([c.body],e);else if(g&&g[3]){var l=c.getElementById(g[3]);if(l&&l.par",
    L"entNode){if(l.id===g[3])return o([l],e)}else return o([],e)}try{return", L" o(c.querySelectorAll(b),e)}catch(p){}}else if(c.nodeType===1&&c.nodeN",
    L"ame.toLowerCase()!==\n\"object\"){var g=c,m=(l=c.getAttribute(\"id\"))", L"||\"__sizzle__\",n=c.parentNode,k=/^\\s*[+~]/.test(b);l?m=m.replace(/'",
    L"/g,\"\\\\$&\"):c.setAttribute(\"id\",m);if(k&&n)c=c.parentNode;try{if(", L"!k||n)return o(c.querySelectorAll(\"[id='\"+m+\"'] \"+b),e)}catch(q){}",
    L"finally{l||g.removeAttribute(\"id\")}}}return a(b,c,e,h)};for(var c in", L" a)i[c]=a[c];b=null}}();(function(){var a=document.documentElement,b=a",
    L".matchesSelector||a.mozMatchesSelector||a.webkitMatchesSelector||a.msM", L"atchesSelector;if(b){var c=!b.call(document.createElement(\"div\"),\n",
    L"\"div\"),d=!1;try{b.call(document.documentElement,\"[test!='']:sizzle", L"\")}catch(f){d=!0}i.matchesSelector=function(a,f){f=f.replace(/\\=\\s*",
    L"([^'\"\\]]*)\\s*\\]/g,\"='$1']\");if(!i.isXML(a))try{if(d||!j.match.PS", L"EUDO.test(f)&&!/!=/.test(f)){var g=b.call(a,f);if(g||!c||a.document&&a",
    L".document.nodeType!==11)return g}}catch(l){}return i(f,null,null,[a]).", L"length>0}}})();(function(){var a=document.createElement(\"div\");a.inn",
    L"erHTML=\"<div class='test e'></div><div class='test'></div>\";if(a.get", L"ElementsByClassName&&a.getElementsByClassName(\"e\").length!==\n0&&(a.",
    L"lastChild.className=\"e\",a.getElementsByClassName(\"e\").length!==1))", L"j.order.splice(1,0,\"CLASS\"),j.find.CLASS=function(a,c,d){if(typeof c",
    L".getElementsByClassName!==\"undefined\"&&!d)return c.getElementsByClas", L"sName(a[1])},a=null})();i.contains=document.documentElement.contains?f",
    L"unction(a,b){return a!==b&&(a.contains?a.contains(b):!0)}:document.doc", L"umentElement.compareDocumentPosition?function(a,b){return!!(a.compareD",
    L"ocumentPosition(b)&16)}:function(){return!1};i.isXML=function(a){retur", L"n(a=(a?a.ownerDocument||\na:0).documentElement)?a.nodeName!==\"HTML\":",
    L"!1};var C=function(a,b){for(var c,d=[],f=\"\",e=b.nodeType?[b]:b;c=j.m", L"atch.PSEUDO.exec(a);)f+=c[0],a=a.replace(j.match.PSEUDO,\"\");a=j.rela",
    L"tive[a]?a+\"*\":a;c=0;for(var h=e.length;c<h;c++)i(a,e[c],d);return i.", L"filter(f,d)};window.Sizzle=i})();", NULL };

} // namespace atoms
} // namespace webdriver

#endif // WEBDRIVER_SIZZLE_H_
