function() {
    return (function() {
            var g, aa = this || self;

            function k(a) {
                return "string" == typeof a
            }

            function ca(a, b) {
                a = a.split(".");
                var c = aa;
                a[0] in c || "undefined" == typeof c.execScript || c.execScript("var " + a[0]);
                for (var d; a.length && (d = a.shift());) a.length || void 0 === b ? c = c[d] && c[d] !== Object.prototype[d] ? c[d] : c[d] = {} : c[d] = b
            }

            function da(a) {
                var b = typeof a;
                if ("object" == b)
                    if (a) {
                        if (a instanceof Array) return "array";
                        if (a instanceof Object) return b;
                        var c = Object.prototype.toString.call(a);
                        if ("[object Window]" == c) return "object";
                        if ("[object Array]" == c || "number" == typeof a.length && "undefined" != typeof a.splice && "undefined" != typeof a.propertyIsEnumerable && !a.propertyIsEnumerable("splice")) return "array";
                        if ("[object Function]" == c || "undefined" != typeof a.call && "undefined" != typeof a.propertyIsEnumerable && !a.propertyIsEnumerable("call")) return "function"
                    } else return "null";
                else if ("function" == b && "undefined" == typeof a.call) return "object";
                return b
            }

            function ea(a) {
                var b = typeof a;
                return "object" == b && null != a || "function" == b
            }

            function fa(a, b, c) {
                return a.call.apply(a.bind, arguments)
            }

            function ha(a, b, c) {
                if (!a) throw Error();
                if (2 < arguments.length) {
                    var d = Array.prototype.slice.call(arguments, 2);
                    return function() {
                        var e = Array.prototype.slice.call(arguments);
                        Array.prototype.unshift.apply(e, d);
                        return a.apply(b, e)
                    }
                }
                return function() {
                    return a.apply(b, arguments)
                }
            }

            function ia(a, b, c) {
                ia = Function.prototype.bind && -1 != Function.prototype.bind.toString()
                    .indexOf("native code") ? fa : ha;
                return ia.apply(null, arguments)
            }

            function ja(a, b) {
                var c = Array.prototype.slice.call(arguments, 1);
                return function() {
                    var d = c.slice();
                    d.push.apply(d, arguments);
                    return a.apply(this, d)
                }
            }

            function m(a, b) {
                function c() {}
                c.prototype = b.prototype;
                a.ka = b.prototype;
                a.prototype = new c;
                a.prototype.constructor = a
            }

            function n(a, b, c) {
                var d = arguments.callee.caller;
                if ("undefined" !== typeof d.ka) {
                    for (var e = Array(arguments.length - 1), f = 1; f < arguments.length; f++) e[f - 1] = arguments[f];
                    d.ka.constructor.apply(a, e)
                } else {
                    if ("string" != typeof b && "symbol" != typeof b) throw Error("method names provided to goog.base must be a string or a symbol");
                    e = Array(arguments.length - 2);
                    for (f = 2; f < arguments.length; f++) e[f - 2] = arguments[f];
                    f = !1;
                    for (var h = a.constructor.prototype; h; h = Object.getPrototypeOf(h))
                        if (h[b] === d) f = !0;
                        else if (f) {
                        h[b].apply(a,
                            e);
                        return
                    }
                    if (a[b] === d) a.constructor.prototype[b].apply(a, e);
                    else throw Error("goog.base called from a method of one name to a method of a different name");
                }
            };
            /*

             The MIT License

             Copyright (c) 2007 Cybozu Labs, Inc.
             Copyright (c) 2012 Google Inc.

             Permission is hereby granted, free of charge, to any person obtaining a copy
             of this software and associated documentation files (the "Software"), to
             deal in the Software without restriction, including without limitation the
             rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
             sell copies of the Software, and to permit persons to whom the Software is
             furnished to do so, subject to the following conditions:

             The above copyright notice and this permission notice shall be included in
             all copies or substantial portions of the Software.

             THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
             IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
             FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
             AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
             LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
             FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
             IN THE SOFTWARE.
            */
            function p(a, b, c) {
                this.u = a;
                this.ua = b || 1;
                this.s = c || 1
            };

            function ka(a, b) {
                if ("string" === typeof a) return "string" !== typeof b || 1 != b.length ? -1 : a.indexOf(b, 0);
                for (var c = 0; c < a.length; c++)
                    if (c in a && a[c] === b) return c;
                return -1
            }

            function r(a, b) {
                for (var c = a.length, d = "string" === typeof a ? a.split("") : a, e = 0; e < c; e++) e in d && b.call(void 0, d[e], e, a)
            }

            function la(a, b) {
                for (var c = a.length, d = Array(c), e = "string" === typeof a ? a.split("") : a, f = 0; f < c; f++) f in e && (d[f] = b.call(void 0, e[f], f, a));
                return d
            }

            function t(a, b, c) {
                var d = c;
                r(a, function(e, f) {
                    d = b.call(void 0, d, e, f, a)
                });
                return d
            }

            function ma(a, b) {
                for (var c = a.length, d = "string" === typeof a ? a.split("") : a, e = 0; e < c; e++)
                    if (e in d && b.call(void 0, d[e], e, a)) return !0;
                return !1
            }

            function na(a) {
                return Array.prototype.concat.apply([], arguments)
            }

            function oa(a, b, c) {
                return 2 >= arguments.length ? Array.prototype.slice.call(a, b) : Array.prototype.slice.call(a, b, c)
            };
            var pa;
            a: {
                var qa = aa.navigator;
                if (qa) {
                    var ra = qa.userAgent;
                    if (ra) {
                        pa = ra;
                        break a
                    }
                }
                pa = ""
            };
            var sa = -1 != pa.indexOf("Macintosh"),
                ta = -1 != pa.indexOf("Windows");

            function ua(a) {
                this.aa = a;
                this.S = 0
            }

            function va(a) {
                a = a.match(wa);
                for (var b = 0; b < a.length; b++) xa.test(a[b]) && a.splice(b, 1);
                return new ua(a)
            }
            var wa = /\$?(?:(?![0-9-\.])(?:\*|[\w-\.]+):)?(?![0-9-\.])(?:\*|[\w-\.]+)|\/\/|\.\.|::|\d+(?:\.\d*)?|\.\d+|"[^"]*"|'[^']*'|[!<>]=|\s+|./g,
                xa = /^\s/;

            function u(a, b) {
                return a.aa[a.S + (b || 0)]
            }
            ua.prototype.next = function() {
                return this.aa[this.S++]
            };
            ua.prototype.back = function() {
                this.S--
            };
            ua.prototype.empty = function() {
                return this.aa.length <= this.S
            };

            function ya(a, b) {
                if (!a || !b) return !1;
                if (a.contains && 1 == b.nodeType) return a == b || a.contains(b);
                if ("undefined" != typeof a.compareDocumentPosition) return a == b || !!(a.compareDocumentPosition(b) & 16);
                for (; b && a != b;) b = b.parentNode;
                return b == a
            }

            function za(a, b) {
                if (a == b) return 0;
                if (a.compareDocumentPosition) return a.compareDocumentPosition(b) & 2 ? 1 : -1;
                if ("sourceIndex" in a || a.parentNode && "sourceIndex" in a.parentNode) {
                    var c = 1 == a.nodeType,
                        d = 1 == b.nodeType;
                    if (c && d) return a.sourceIndex - b.sourceIndex;
                    var e = a.parentNode,
                        f = b.parentNode;
                    return e == f ? Aa(a, b) : !c && ya(e, b) ? -1 * Ba(a, b) : !d && ya(f, a) ? Ba(b, a) : (c ? a.sourceIndex : e.sourceIndex) - (d ? b.sourceIndex : f.sourceIndex)
                }
                d = v(a);
                c = d.createRange();
                c.selectNode(a);
                c.collapse(!0);
                a = d.createRange();
                a.selectNode(b);
                a.collapse(!0);
                return c.compareBoundaryPoints(aa.Range.START_TO_END, a)
            }

            function Ba(a, b) {
                var c = a.parentNode;
                if (c == b) return -1;
                for (; b.parentNode != c;) b = b.parentNode;
                return Aa(b, a)
            }

            function Aa(a, b) {
                for (; b = b.previousSibling;)
                    if (b == a) return -1;
                return 1
            }

            function v(a) {
                return 9 == a.nodeType ? a : a.ownerDocument || a.document
            };

            function w(a) {
                var b = null,
                    c = a.nodeType;
                1 == c && (b = a.textContent, b = void 0 == b || null == b ? a.innerText : b, b = void 0 == b || null == b ? "" : b);
                if ("string" != typeof b)
                    if (9 == c || 1 == c) {
                        a = 9 == c ? a.documentElement : a.firstChild;
                        c = 0;
                        var d = [];
                        for (b = ""; a;) {
                            do 1 != a.nodeType && (b += a.nodeValue), d[c++] = a; while (a = a.firstChild);
                            for (; c && !(a = d[--c].nextSibling););
                        }
                    } else b = a.nodeValue;
                return "" + b
            }

            function y(a, b, c) {
                if (null === b) return !0;
                try {
                    if (!a.getAttribute) return !1
                } catch (d) {
                    return !1
                }
                return null == c ? !!a.getAttribute(b) : a.getAttribute(b, 2) == c
            }

            function z(a, b, c, d, e) {
                return Ca.call(null, a, b, k(c) ? c : null, k(d) ? d : null, e || new A)
            }

            function Ca(a, b, c, d, e) {
                b.getElementsByName && d && "name" == c ? (b = b.getElementsByName(d), r(b, function(f) {
                    a.matches(f) && e.add(f)
                })) : b.getElementsByClassName && d && "class" == c ? (b = b.getElementsByClassName(d), r(b, function(f) {
                    f.className == d && a.matches(f) && e.add(f)
                })) : a instanceof B ? Da(a, b, c, d, e) : b.getElementsByTagName && (b = b.getElementsByTagName(a.K()), r(b, function(f) {
                    y(f, c, d) && e.add(f)
                }));
                return e
            }

            function Da(a, b, c, d, e) {
                for (b = b.firstChild; b; b = b.nextSibling) y(b, c, d) && a.matches(b) && e.add(b), Da(a, b, c, d, e)
            };

            function A() {
                this.s = this.i = null;
                this.L = 0
            }

            function Ea(a) {
                this.node = a;
                this.next = this.G = null
            }

            function Fa(a, b) {
                if (!a.i) return b;
                if (!b.i) return a;
                var c = a.i;
                b = b.i;
                for (var d = null, e, f = 0; c && b;) c.node == b.node ? (e = c, c = c.next, b = b.next) : 0 < za(c.node, b.node) ? (e = b, b = b.next) : (e = c, c = c.next), (e.G = d) ? d.next = e : a.i = e, d = e, f++;
                for (e = c || b; e;) e.G = d, d = d.next = e, f++, e = e.next;
                a.s = d;
                a.L = f;
                return a
            }
            A.prototype.unshift = function(a) {
                a = new Ea(a);
                a.next = this.i;
                this.s ? this.i.G = a : this.i = this.s = a;
                this.i = a;
                this.L++
            };
            A.prototype.add = function(a) {
                a = new Ea(a);
                a.G = this.s;
                this.i ? this.s.next = a : this.i = this.s = a;
                this.s = a;
                this.L++
            };

            function Ga(a) {
                return (a = a.i) ? a.node : null
            }
            A.prototype.v = function() {
                return this.L
            };

            function Ha(a) {
                return (a = Ga(a)) ? w(a) : ""
            }
            A.prototype.iterator = function(a) {
                return new Ia(this, !!a)
            };

            function Ia(a, b) {
                this.qa = a;
                this.ba = (this.I = b) ? a.s : a.i;
                this.Y = null
            }
            Ia.prototype.next = function() {
                var a = this.ba;
                if (null == a) return null;
                var b = this.Y = a;
                this.ba = this.I ? a.G : a.next;
                return b.node
            };
            Ia.prototype.remove = function() {
                var a = this.qa,
                    b = this.Y;
                if (!b) throw Error("Next must be called at least once before remove.");
                var c = b.G;
                b = b.next;
                c ? c.next = b : a.i = b;
                b ? b.G = c : a.s = c;
                a.L--;
                this.Y = null
            };

            function C(a) {
                this.h = a;
                this.l = this.A = !1;
                this.M = null
            }

            function D(a) {
                return "\n  " + a.toString()
                    .split("\n")
                    .join("\n  ")
            }
            C.prototype.g = function() {
                return this.A
            };

            function Ja(a, b) {
                a.A = b
            }

            function Ka(a, b) {
                a.l = b
            }
            C.prototype.C = function() {
                return this.M
            };

            function E(a, b) {
                a = a.evaluate(b);
                return a instanceof A ? +Ha(a) : +a
            }

            function F(a, b) {
                a = a.evaluate(b);
                return a instanceof A ? Ha(a) : "" + a
            }

            function G(a, b) {
                a = a.evaluate(b);
                return a instanceof A ? !!a.v() : !!a
            };

            function J(a, b, c) {
                C.call(this, a.h);
                this.$ = a;
                this.ea = b;
                this.ja = c;
                this.A = b.g() || c.g();
                this.l = b.l || c.l;
                this.$ == La && (c.l || c.g() || 4 == c.h || 0 == c.h || !b.C() ? b.l || b.g() || 4 == b.h || 0 == b.h || !c.C() || (this.M = {
                    name: c.C()
                        .name,
                    J: b
                }) : this.M = {
                    name: b.C()
                        .name,
                    J: c
                })
            }
            m(J, C);

            function K(a, b, c, d, e) {
                b = b.evaluate(d);
                c = c.evaluate(d);
                var f;
                if (b instanceof A && c instanceof A) {
                    b = b.iterator();
                    for (d = b.next(); d; d = b.next())
                        for (e = c.iterator(), f = e.next(); f; f = e.next())
                            if (a(w(d), w(f))) return !0;
                    return !1
                }
                if (b instanceof A || c instanceof A) {
                    b instanceof A ? (e = b, d = c) : (e = c, d = b);
                    f = e.iterator();
                    for (var h = typeof d, l = f.next(); l; l = f.next()) {
                        switch (h) {
                            case "number":
                                l = +w(l);
                                break;
                            case "boolean":
                                l = !!w(l);
                                break;
                            case "string":
                                l = w(l);
                                break;
                            default:
                                throw Error("Illegal primitive type for comparison.");
                        }
                        if (e == b && a(l, d) || e == c && a(d, l)) return !0
                    }
                    return !1
                }
                return e ? "boolean" == typeof b || "boolean" == typeof c ? a(!!b, !!c) : "number" == typeof b || "number" == typeof c ? a(+b, +c) : a(b, c) : a(+b, +c)
            }
            J.prototype.evaluate = function(a) {
                return this.$.F(this.ea, this.ja, a)
            };
            J.prototype.toString = function() {
                var a = "Binary Expression: " + this.$;
                a += D(this.ea);
                return a += D(this.ja)
            };

            function Ma(a, b, c, d) {
                this.ta = a;
                this.ha = b;
                this.h = c;
                this.F = d
            }
            Ma.prototype.toString = function() {
                return this.ta
            };
            var Oa = {};

            function L(a, b, c, d) {
                if (Oa.hasOwnProperty(a)) throw Error("Binary operator already created: " + a);
                a = new Ma(a, b, c, d);
                return Oa[a.toString()] = a
            }
            L("div", 6, 1, function(a, b, c) {
                return E(a, c) / E(b, c)
            });
            L("mod", 6, 1, function(a, b, c) {
                return E(a, c) % E(b, c)
            });
            L("*", 6, 1, function(a, b, c) {
                return E(a, c) * E(b, c)
            });
            L("+", 5, 1, function(a, b, c) {
                return E(a, c) + E(b, c)
            });
            L("-", 5, 1, function(a, b, c) {
                return E(a, c) - E(b, c)
            });
            L("<", 4, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d < e
                }, a, b, c)
            });
            L(">", 4, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d > e
                }, a, b, c)
            });
            L("<=", 4, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d <= e
                }, a, b, c)
            });
            L(">=", 4, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d >= e
                }, a, b, c)
            });
            var La = L("=", 3, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d == e
                }, a, b, c, !0)
            });
            L("!=", 3, 2, function(a, b, c) {
                return K(function(d, e) {
                    return d != e
                }, a, b, c, !0)
            });
            L("and", 2, 2, function(a, b, c) {
                return G(a, c) && G(b, c)
            });
            L("or", 1, 2, function(a, b, c) {
                return G(a, c) || G(b, c)
            });

            function Pa(a, b) {
                if (b.v() && 4 != a.h) throw Error("Primary expression must evaluate to nodeset if filter has predicate(s).");
                C.call(this, a.h);
                this.ia = a;
                this.f = b;
                this.A = a.g();
                this.l = a.l
            }
            m(Pa, C);
            Pa.prototype.evaluate = function(a) {
                a = this.ia.evaluate(a);
                return Qa(this.f, a)
            };
            Pa.prototype.toString = function() {
                var a = "Filter:" + D(this.ia);
                return a += D(this.f)
            };

            function Ra(a, b) {
                if (b.length < a.ga) throw Error("Function " + a.m + " expects at least" + a.ga + " arguments, " + b.length + " given");
                if (null !== a.Z && b.length > a.Z) throw Error("Function " + a.m + " expects at most " + a.Z + " arguments, " + b.length + " given");
                a.ra && r(b, function(c, d) {
                    if (4 != c.h) throw Error("Argument " + d + " to function " + a.m + " is not of type Nodeset: " + c);
                });
                C.call(this, a.h);
                this.R = a;
                this.W = b;
                Ja(this, a.A || ma(b, function(c) {
                    return c.g()
                }));
                Ka(this, a.pa && !b.length || a.oa && !!b.length || ma(b, function(c) {
                    return c.l
                }))
            }
            m(Ra, C);
            Ra.prototype.evaluate = function(a) {
                return this.R.F.apply(null, na(a, this.W))
            };
            Ra.prototype.toString = function() {
                var a = "Function: " + this.R;
                if (this.W.length) {
                    var b = t(this.W, function(c, d) {
                        return c + D(d)
                    }, "Arguments:");
                    a += D(b)
                }
                return a
            };

            function Sa(a, b, c, d, e, f, h, l) {
                this.m = a;
                this.h = b;
                this.A = c;
                this.pa = d;
                this.oa = !1;
                this.F = e;
                this.ga = f;
                this.Z = void 0 !== h ? h : f;
                this.ra = !!l
            }
            Sa.prototype.toString = function() {
                return this.m
            };
            var Ta = {};

            function M(a, b, c, d, e, f, h, l) {
                if (Ta.hasOwnProperty(a)) throw Error("Function already created: " + a + ".");
                Ta[a] = new Sa(a, b, c, d, e, f, h, l)
            }
            M("boolean", 2, !1, !1, function(a, b) {
                return G(b, a)
            }, 1);
            M("ceiling", 1, !1, !1, function(a, b) {
                return Math.ceil(E(b, a))
            }, 1);
            M("concat", 3, !1, !1, function(a, b) {
                return t(oa(arguments, 1), function(c, d) {
                    return c + F(d, a)
                }, "")
            }, 2, null);
            M("contains", 2, !1, !1, function(a, b, c) {
                b = F(b, a);
                a = F(c, a);
                return -1 != b.indexOf(a)
            }, 2);
            M("count", 1, !1, !1, function(a, b) {
                return b.evaluate(a)
                    .v()
            }, 1, 1, !0);
            M("false", 2, !1, !1, function() {
                return !1
            }, 0);
            M("floor", 1, !1, !1, function(a, b) {
                return Math.floor(E(b, a))
            }, 1);
            M("id", 4, !1, !1, function(a, b) {
                var c = a.u,
                    d = 9 == c.nodeType ? c : c.ownerDocument;
                a = F(b, a)
                    .split(/\s+/);
                var e = [];
                r(a, function(h) {
                    h = d.getElementById(h);
                    !h || 0 <= ka(e, h) || e.push(h)
                });
                e.sort(za);
                var f = new A;
                r(e, function(h) {
                    f.add(h)
                });
                return f
            }, 1);
            M("lang", 2, !1, !1, function() {
                return !1
            }, 1);
            M("last", 1, !0, !1, function(a) {
                if (1 != arguments.length) throw Error("Function last expects ()");
                return a.s
            }, 0);
            M("local-name", 3, !1, !0, function(a, b) {
                return (a = b ? Ga(b.evaluate(a)) : a.u) ? a.localName || a.nodeName.toLowerCase() : ""
            }, 0, 1, !0);
            M("name", 3, !1, !0, function(a, b) {
                return (a = b ? Ga(b.evaluate(a)) : a.u) ? a.nodeName.toLowerCase() : ""
            }, 0, 1, !0);
            M("namespace-uri", 3, !0, !1, function() {
                return ""
            }, 0, 1, !0);
            M("normalize-space", 3, !1, !0, function(a, b) {
                return (b ? F(b, a) : w(a.u))
                    .replace(/[\s\xa0]+/g, " ")
                    .replace(/^\s+|\s+$/g, "")
            }, 0, 1);
            M("not", 2, !1, !1, function(a, b) {
                return !G(b, a)
            }, 1);
            M("number", 1, !1, !0, function(a, b) {
                return b ? E(b, a) : +w(a.u)
            }, 0, 1);
            M("position", 1, !0, !1, function(a) {
                return a.ua
            }, 0);
            M("round", 1, !1, !1, function(a, b) {
                return Math.round(E(b, a))
            }, 1);
            M("starts-with", 2, !1, !1, function(a, b, c) {
                b = F(b, a);
                a = F(c, a);
                return 0 == b.lastIndexOf(a, 0)
            }, 2);
            M("string", 3, !1, !0, function(a, b) {
                return b ? F(b, a) : w(a.u)
            }, 0, 1);
            M("string-length", 1, !1, !0, function(a, b) {
                return (b ? F(b, a) : w(a.u))
                    .length
            }, 0, 1);
            M("substring", 3, !1, !1, function(a, b, c, d) {
                c = E(c, a);
                if (isNaN(c) || Infinity == c || -Infinity == c) return "";
                d = d ? E(d, a) : Infinity;
                if (isNaN(d) || -Infinity === d) return "";
                c = Math.round(c) - 1;
                var e = Math.max(c, 0);
                a = F(b, a);
                return Infinity == d ? a.substring(e) : a.substring(e, c + Math.round(d))
            }, 2, 3);
            M("substring-after", 3, !1, !1, function(a, b, c) {
                b = F(b, a);
                a = F(c, a);
                c = b.indexOf(a);
                return -1 == c ? "" : b.substring(c + a.length)
            }, 2);
            M("substring-before", 3, !1, !1, function(a, b, c) {
                b = F(b, a);
                a = F(c, a);
                a = b.indexOf(a);
                return -1 == a ? "" : b.substring(0, a)
            }, 2);
            M("sum", 1, !1, !1, function(a, b) {
                a = b.evaluate(a)
                    .iterator();
                b = 0;
                for (var c = a.next(); c; c = a.next()) b += +w(c);
                return b
            }, 1, 1, !0);
            M("translate", 3, !1, !1, function(a, b, c, d) {
                b = F(b, a);
                c = F(c, a);
                var e = F(d, a);
                a = {};
                for (d = 0; d < c.length; d++) {
                    var f = c.charAt(d);
                    f in a || (a[f] = e.charAt(d))
                }
                c = "";
                for (d = 0; d < b.length; d++) f = b.charAt(d), c += f in a ? a[f] : f;
                return c
            }, 3);
            M("true", 2, !1, !1, function() {
                return !0
            }, 0);

            function B(a, b) {
                this.ma = a;
                this.fa = void 0 !== b ? b : null;
                this.o = null;
                switch (a) {
                    case "comment":
                        this.o = 8;
                        break;
                    case "text":
                        this.o = 3;
                        break;
                    case "processing-instruction":
                        this.o = 7;
                        break;
                    case "node":
                        break;
                    default:
                        throw Error("Unexpected argument");
                }
            }

            function Ua(a) {
                return "comment" == a || "text" == a || "processing-instruction" == a || "node" == a
            }
            B.prototype.matches = function(a) {
                return null === this.o || this.o == a.nodeType
            };
            B.prototype.K = function() {
                return this.ma
            };
            B.prototype.toString = function() {
                var a = "Kind Test: " + this.ma;
                null === this.fa || (a += D(this.fa));
                return a
            };

            function Va(a) {
                C.call(this, 3);
                this.la = a.substring(1, a.length - 1)
            }
            m(Va, C);
            Va.prototype.evaluate = function() {
                return this.la
            };
            Va.prototype.toString = function() {
                return "Literal: " + this.la
            };

            function N(a, b) {
                this.m = a.toLowerCase();
                a = "*" == this.m ? "*" : "http://www.w3.org/1999/xhtml";
                this.T = b ? b.toLowerCase() : a
            }
            N.prototype.matches = function(a) {
                var b = a.nodeType;
                if (1 != b && 2 != b) return !1;
                b = void 0 !== a.localName ? a.localName : a.nodeName;
                return "*" != this.m && this.m != b.toLowerCase() ? !1 : "*" == this.T ? !0 : this.T == (a.namespaceURI ? a.namespaceURI.toLowerCase() : "http://www.w3.org/1999/xhtml")
            };
            N.prototype.K = function() {
                return this.m
            };
            N.prototype.toString = function() {
                return "Name Test: " + ("http://www.w3.org/1999/xhtml" == this.T ? "" : this.T + ":") + this.m
            };

            function Wa(a) {
                C.call(this, 1);
                this.na = a
            }
            m(Wa, C);
            Wa.prototype.evaluate = function() {
                return this.na
            };
            Wa.prototype.toString = function() {
                return "Number: " + this.na
            };

            function Xa(a, b) {
                C.call(this, a.h);
                this.da = a;
                this.N = b;
                this.A = a.g();
                this.l = a.l;
                1 == this.N.length && (a = this.N[0], a.X || a.B != Ya || (a = a.V, "*" != a.K() && (this.M = {
                    name: a.K(),
                    J: null
                })))
            }
            m(Xa, C);

            function Za() {
                C.call(this, 4)
            }
            m(Za, C);
            Za.prototype.evaluate = function(a) {
                var b = new A;
                a = a.u;
                9 == a.nodeType ? b.add(a) : b.add(a.ownerDocument);
                return b
            };
            Za.prototype.toString = function() {
                return "Root Helper Expression"
            };

            function $a() {
                C.call(this, 4)
            }
            m($a, C);
            $a.prototype.evaluate = function(a) {
                var b = new A;
                b.add(a.u);
                return b
            };
            $a.prototype.toString = function() {
                return "Context Helper Expression"
            };

            function ab(a) {
                return "/" == a || "//" == a
            }
            Xa.prototype.evaluate = function(a) {
                var b = this.da.evaluate(a);
                if (!(b instanceof A)) throw Error("Filter expression must evaluate to nodeset.");
                a = this.N;
                for (var c = 0, d = a.length; c < d && b.v(); c++) {
                    var e = a[c],
                        f = b.iterator(e.B.I);
                    if (e.g() || e.B != bb)
                        if (e.g() || e.B != cb) {
                            var h = f.next();
                            for (b = e.evaluate(new p(h)); null != (h = f.next());) h = e.evaluate(new p(h)), b = Fa(b, h)
                        } else h = f.next(), b = e.evaluate(new p(h));
                    else {
                        for (h = f.next();
                            (b = f.next()) && (!h.contains || h.contains(b)) && b.compareDocumentPosition(h) & 8; h = b);
                        b = e.evaluate(new p(h))
                    }
                }
                return b
            };
            Xa.prototype.toString = function() {
                var a = "Path Expression:" + D(this.da);
                if (this.N.length) {
                    var b = t(this.N, function(c, d) {
                        return c + D(d)
                    }, "Steps:");
                    a += D(b)
                }
                return a
            };

            function P(a, b) {
                this.f = a;
                this.I = !!b
            }

            function Qa(a, b, c) {
                for (c = c || 0; c < a.f.length; c++)
                    for (var d = a.f[c], e = b.iterator(), f = b.v(), h, l = 0; h = e.next(); l++) {
                        var x = a.I ? f - l : l + 1;
                        h = d.evaluate(new p(h, x, f));
                        if ("number" == typeof h) x = x == h;
                        else if ("string" == typeof h || "boolean" == typeof h) x = !!h;
                        else if (h instanceof A) x = 0 < h.v();
                        else throw Error("Predicate.evaluate returned an unexpected type.");
                        x || e.remove()
                    }
                return b
            }
            P.prototype.C = function() {
                return 0 < this.f.length ? this.f[0].C() : null
            };
            P.prototype.g = function() {
                for (var a = 0; a < this.f.length; a++) {
                    var b = this.f[a];
                    if (b.g() || 1 == b.h || 0 == b.h) return !0
                }
                return !1
            };
            P.prototype.v = function() {
                return this.f.length
            };
            P.prototype.toString = function() {
                return t(this.f, function(a, b) {
                    return a + D(b)
                }, "Predicates:")
            };

            function Q(a, b, c, d) {
                C.call(this, 4);
                this.B = a;
                this.V = b;
                this.f = c || new P([]);
                this.X = !!d;
                b = this.f.C();
                a.va && b && (this.M = {
                    name: b.name,
                    J: b.J
                });
                this.A = this.f.g()
            }
            m(Q, C);
            Q.prototype.evaluate = function(a) {
                var b = a.u,
                    c = this.C(),
                    d = null,
                    e = null,
                    f = 0;
                c && (d = c.name, e = c.J ? F(c.J, a) : null, f = 1);
                if (this.X)
                    if (this.g() || this.B != db)
                        if (b = (new Q(eb, new B("node")))
                            .evaluate(a)
                            .iterator(), c = b.next())
                            for (a = this.F(c, d, e, f); null != (c = b.next());) a = Fa(a, this.F(c, d, e, f));
                        else a = new A;
                else a = z(this.V, b, d, e), a = Qa(this.f, a, f);
                else a = this.F(a.u, d, e, f);
                return a
            };
            Q.prototype.F = function(a, b, c, d) {
                a = this.B.R(this.V, a, b, c);
                return a = Qa(this.f, a, d)
            };
            Q.prototype.toString = function() {
                var a = "Step:" + D("Operator: " + (this.X ? "//" : "/"));
                this.B.m && (a += D("Axis: " + this.B));
                a += D(this.V);
                if (this.f.v()) {
                    var b = t(this.f.f, function(c, d) {
                        return c + D(d)
                    }, "Predicates:");
                    a += D(b)
                }
                return a
            };

            function fb(a, b, c, d) {
                this.m = a;
                this.R = b;
                this.I = c;
                this.va = d
            }
            fb.prototype.toString = function() {
                return this.m
            };
            var gb = {};

            function R(a, b, c, d) {
                if (gb.hasOwnProperty(a)) throw Error("Axis already created: " + a);
                b = new fb(a, b, c, !!d);
                return gb[a] = b
            }
            R("ancestor", function(a, b) {
                for (var c = new A; b = b.parentNode;) a.matches(b) && c.unshift(b);
                return c
            }, !0);
            R("ancestor-or-self", function(a, b) {
                var c = new A;
                do a.matches(b) && c.unshift(b); while (b = b.parentNode);
                return c
            }, !0);
            var Ya = R("attribute", function(a, b) {
                    var c = new A,
                        d = a.K();
                    if (b = b.attributes)
                        if (a instanceof B && null === a.o || "*" == d)
                            for (a = 0; d = b[a]; a++) c.add(d);
                        else(d = b.getNamedItem(d)) && c.add(d);
                    return c
                }, !1),
                db = R("child", function(a, b, c, d, e) {
                    c = k(c) ? c : null;
                    d = k(d) ? d : null;
                    e = e || new A;
                    for (b = b.firstChild; b; b = b.nextSibling) y(b, c, d) && a.matches(b) && e.add(b);
                    return e
                }, !1, !0);
            R("descendant", z, !1, !0);
            var eb = R("descendant-or-self", function(a, b, c, d) {
                    var e = new A;
                    y(b, c, d) && a.matches(b) && e.add(b);
                    return z(a, b, c, d, e)
                }, !1, !0),
                bb = R("following", function(a, b, c, d) {
                    var e = new A;
                    do
                        for (var f = b; f = f.nextSibling;) y(f, c, d) && a.matches(f) && e.add(f), e = z(a, f, c, d, e); while (b = b.parentNode);
                    return e
                }, !1, !0);
            R("following-sibling", function(a, b) {
                for (var c = new A; b = b.nextSibling;) a.matches(b) && c.add(b);
                return c
            }, !1);
            R("namespace", function() {
                return new A
            }, !1);
            var hb = R("parent", function(a, b) {
                    var c = new A;
                    if (9 == b.nodeType) return c;
                    if (2 == b.nodeType) return c.add(b.ownerElement), c;
                    b = b.parentNode;
                    a.matches(b) && c.add(b);
                    return c
                }, !1),
                cb = R("preceding", function(a, b, c, d) {
                    var e = new A,
                        f = [];
                    do f.unshift(b); while (b = b.parentNode);
                    for (var h = 1, l = f.length; h < l; h++) {
                        var x = [];
                        for (b = f[h]; b = b.previousSibling;) x.unshift(b);
                        for (var ba = 0, Na = x.length; ba < Na; ba++) b = x[ba], y(b, c, d) && a.matches(b) && e.add(b), e = z(a, b, c, d, e)
                    }
                    return e
                }, !0, !0);
            R("preceding-sibling", function(a, b) {
                for (var c = new A; b = b.previousSibling;) a.matches(b) && c.unshift(b);
                return c
            }, !0);
            var ib = R("self", function(a, b) {
                var c = new A;
                a.matches(b) && c.add(b);
                return c
            }, !1);

            function jb(a) {
                C.call(this, 1);
                this.ca = a;
                this.A = a.g();
                this.l = a.l
            }
            m(jb, C);
            jb.prototype.evaluate = function(a) {
                return -E(this.ca, a)
            };
            jb.prototype.toString = function() {
                return "Unary Expression: -" + D(this.ca)
            };

            function kb(a) {
                C.call(this, 4);
                this.U = a;
                Ja(this, ma(this.U, function(b) {
                    return b.g()
                }));
                Ka(this, ma(this.U, function(b) {
                    return b.l
                }))
            }
            m(kb, C);
            kb.prototype.evaluate = function(a) {
                var b = new A;
                r(this.U, function(c) {
                    c = c.evaluate(a);
                    if (!(c instanceof A)) throw Error("Path expression must evaluate to NodeSet.");
                    b = Fa(b, c)
                });
                return b
            };
            kb.prototype.toString = function() {
                return t(this.U, function(a, b) {
                    return a + D(b)
                }, "Union Expression:")
            };

            function lb(a, b) {
                this.a = a;
                this.sa = b
            }

            function mb(a) {
                for (var b, c = [];;) {
                    S(a, "Missing right hand side of binary expression.");
                    b = nb(a);
                    var d = a.a.next();
                    if (!d) break;
                    var e = (d = Oa[d] || null) && d.ha;
                    if (!e) {
                        a.a.back();
                        break
                    }
                    for (; c.length && e <= c[c.length - 1].ha;) b = new J(c.pop(), c.pop(), b);
                    c.push(b, d)
                }
                for (; c.length;) b = new J(c.pop(), c.pop(), b);
                return b
            }

            function S(a, b) {
                if (a.a.empty()) throw Error(b);
            }

            function ob(a, b) {
                a = a.a.next();
                if (a != b) throw Error("Bad token, expected: " + b + " got: " + a);
            }

            function pb(a) {
                a = a.a.next();
                if (")" != a) throw Error("Bad token: " + a);
            }

            function qb(a) {
                a = a.a.next();
                if (2 > a.length) throw Error("Unclosed literal string");
                return new Va(a)
            }

            function rb(a) {
                var b = [];
                if (ab(u(a.a))) {
                    var c = a.a.next();
                    var d = u(a.a);
                    if ("/" == c && (a.a.empty() || "." != d && ".." != d && "@" != d && "*" != d && !/(?![0-9])[\w]/.test(d))) return new Za;
                    d = new Za;
                    S(a, "Missing next location step.");
                    c = sb(a, c);
                    b.push(c)
                } else {
                    a: {
                        c = u(a.a);d = c.charAt(0);
                        switch (d) {
                            case "$":
                                throw Error("Variable reference not allowed in HTML XPath");
                            case "(":
                                a.a.next();
                                c = mb(a);
                                S(a, 'unclosed "("');
                                ob(a, ")");
                                break;
                            case '"':
                            case "'":
                                c = qb(a);
                                break;
                            default:
                                if (isNaN(+c))
                                    if (!Ua(c) && /(?![0-9])[\w]/.test(d) && "(" == u(a.a,
                                        1)) {
                                        c = a.a.next();
                                        c = Ta[c] || null;
                                        a.a.next();
                                        for (d = [];
                                            ")" != u(a.a);) {
                                            S(a, "Missing function argument list.");
                                            d.push(mb(a));
                                            if ("," != u(a.a)) break;
                                            a.a.next()
                                        }
                                        S(a, "Unclosed function argument list.");
                                        pb(a);
                                        c = new Ra(c, d)
                                    } else {
                                        c = null;
                                        break a
                                    }
                                else c = new Wa(+a.a.next())
                        }
                        "[" == u(a.a) && (d = new P(tb(a)), c = new Pa(c, d))
                    }
                    if (c)
                        if (ab(u(a.a))) d = c;
                        else return c;
                    else c = sb(a, "/"),
                    d = new $a,
                    b.push(c)
                }
                for (; ab(u(a.a));) c = a.a.next(), S(a, "Missing next location step."), c = sb(a, c), b.push(c);
                return new Xa(d, b)
            }

            function sb(a, b) {
                if ("/" != b && "//" != b) throw Error('Step op should be "/" or "//"');
                if ("." == u(a.a)) {
                    var c = new Q(ib, new B("node"));
                    a.a.next();
                    return c
                }
                if (".." == u(a.a)) return c = new Q(hb, new B("node")), a.a.next(), c;
                if ("@" == u(a.a)) {
                    var d = Ya;
                    a.a.next();
                    S(a, "Missing attribute name")
                } else if ("::" == u(a.a, 1)) {
                    if (!/(?![0-9])[\w]/.test(u(a.a)
                        .charAt(0))) throw Error("Bad token: " + a.a.next());
                    var e = a.a.next();
                    d = gb[e] || null;
                    if (!d) throw Error("No axis with name: " + e);
                    a.a.next();
                    S(a, "Missing node name")
                } else d = db;
                e =
                    u(a.a);
                if (/(?![0-9])[\w\*]/.test(e.charAt(0)))
                    if ("(" == u(a.a, 1)) {
                        if (!Ua(e)) throw Error("Invalid node type: " + e);
                        e = a.a.next();
                        if (!Ua(e)) throw Error("Invalid type name: " + e);
                        ob(a, "(");
                        S(a, "Bad nodetype");
                        var f = u(a.a)
                            .charAt(0),
                            h = null;
                        if ('"' == f || "'" == f) h = qb(a);
                        S(a, "Bad nodetype");
                        pb(a);
                        e = new B(e, h)
                    } else if (e = a.a.next(), f = e.indexOf(":"), -1 == f) e = new N(e);
                else {
                    h = e.substring(0, f);
                    if ("*" == h) var l = "*";
                    else if (l = a.sa(h), !l) throw Error("Namespace prefix not declared: " + h);
                    e = e.substr(f + 1);
                    e = new N(e, l)
                } else throw Error("Bad token: " +
                    a.a.next());
                a = new P(tb(a), d.I);
                return c || new Q(d, e, a, "//" == b)
            }

            function tb(a) {
                for (var b = [];
                    "[" == u(a.a);) {
                    a.a.next();
                    S(a, "Missing predicate expression.");
                    var c = mb(a);
                    b.push(c);
                    S(a, "Unclosed predicate expression.");
                    ob(a, "]")
                }
                return b
            }

            function nb(a) {
                if ("-" == u(a.a)) return a.a.next(), new jb(nb(a));
                var b = rb(a);
                if ("|" != u(a.a)) a = b;
                else {
                    for (b = [b];
                        "|" == a.a.next();) S(a, "Missing next union location path."), b.push(rb(a));
                    a.a.back();
                    a = new kb(b)
                }
                return a
            };

            function ub(a) {
                switch (a.nodeType) {
                    case 1:
                        return ja(vb, a);
                    case 9:
                        return ub(a.documentElement);
                    case 11:
                    case 10:
                    case 6:
                    case 12:
                        return wb;
                    default:
                        return a.parentNode ? ub(a.parentNode) : wb
                }
            }

            function wb() {
                return null
            }

            function vb(a, b) {
                if (a.prefix == b) return a.namespaceURI || "http://www.w3.org/1999/xhtml";
                var c = a.getAttributeNode("xmlns:" + b);
                return c && c.specified ? c.value || null : a.parentNode && 9 != a.parentNode.nodeType ? vb(a.parentNode, b) : null
            };

            function xb(a, b) {
                if (!a.length) throw Error("Empty XPath expression.");
                a = va(a);
                if (a.empty()) throw Error("Invalid XPath expression.");
                b ? "function" == da(b) || (b = ia(b.lookupNamespaceURI, b)) : b = function() {
                    return null
                };
                var c = mb(new lb(a, b));
                if (!a.empty()) throw Error("Bad token: " + a.next());
                this.evaluate = function(d, e) {
                    d = c.evaluate(new p(d));
                    return new T(d, e)
                }
            }

            function T(a, b) {
                if (0 == b)
                    if (a instanceof A) b = 4;
                    else if ("string" == typeof a) b = 2;
                else if ("number" == typeof a) b = 1;
                else if ("boolean" == typeof a) b = 3;
                else throw Error("Unexpected evaluation result.");
                if (2 != b && 1 != b && 3 != b && !(a instanceof A)) throw Error("value could not be converted to the specified type");
                this.resultType = b;
                switch (b) {
                    case 2:
                        this.stringValue = a instanceof A ? Ha(a) : "" + a;
                        break;
                    case 1:
                        this.numberValue = a instanceof A ? +Ha(a) : +a;
                        break;
                    case 3:
                        this.booleanValue = a instanceof A ? 0 < a.v() : !!a;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        var c =
                            a.iterator();
                        var d = [];
                        for (var e = c.next(); e; e = c.next()) d.push(e);
                        this.snapshotLength = a.v();
                        this.invalidIteratorState = !1;
                        break;
                    case 8:
                    case 9:
                        this.singleNodeValue = Ga(a);
                        break;
                    default:
                        throw Error("Unknown XPathResult type.");
                }
                var f = 0;
                this.iterateNext = function() {
                    if (4 != b && 5 != b) throw Error("iterateNext called with wrong result type");
                    return f >= d.length ? null : d[f++]
                };
                this.snapshotItem = function(h) {
                    if (6 != b && 7 != b) throw Error("snapshotItem called with wrong result type");
                    return h >= d.length || 0 > h ? null : d[h]
                }
            }
            T.ANY_TYPE = 0;
            T.NUMBER_TYPE = 1;
            T.STRING_TYPE = 2;
            T.BOOLEAN_TYPE = 3;
            T.UNORDERED_NODE_ITERATOR_TYPE = 4;
            T.ORDERED_NODE_ITERATOR_TYPE = 5;
            T.UNORDERED_NODE_SNAPSHOT_TYPE = 6;
            T.ORDERED_NODE_SNAPSHOT_TYPE = 7;
            T.ANY_UNORDERED_NODE_TYPE = 8;
            T.FIRST_ORDERED_NODE_TYPE = 9;

            function yb(a) {
                this.lookupNamespaceURI = ub(a)
            }

            function zb(a, b) {
                a = a || aa;
                var c = a.Document && a.Document.prototype || a.document;
                if (!c.evaluate || b) a.XPathResult = T, c.evaluate = function(d, e, f, h) {
                    return (new xb(d, f))
                        .evaluate(e, h)
                }, c.createExpression = function(d, e) {
                    return new xb(d, e)
                }, c.createNSResolver = function(d) {
                    return new yb(d)
                }
            }
            ca("wgxpath.install", zb);
            ca("wgxpath.install", zb);

            function Ab(a, b) {
                this.code = a;
                this.state = U[a] || Bb;
                this.message = b || "";
                a = this.state.replace(/((?:^|\s+)[a-z])/g, function(c) {
                    return c.toUpperCase()
                        .replace(/^[\s\xa0]+/g, "")
                });
                b = a.length - 5;
                if (0 > b || a.indexOf("Error", b) != b) a += "Error";
                this.name = a;
                a = Error(this.message);
                a.name = this.name;
                this.stack = a.stack || ""
            }
            m(Ab, Error);
            var Bb = "unknown error",
                U = {
                    15: "element not selectable",
                    11: "element not visible"
                };
            U[31] = Bb;
            U[30] = Bb;
            U[24] = "invalid cookie domain";
            U[29] = "invalid element coordinates";
            U[12] = "invalid element state";
            U[32] = "invalid selector";
            U[51] = "invalid selector";
            U[52] = "invalid selector";
            U[17] = "javascript error";
            U[405] = "unsupported operation";
            U[34] = "move target out of bounds";
            U[27] = "no such alert";
            U[7] = "no such element";
            U[8] = "no such frame";
            U[23] = "no such window";
            U[28] = "script timeout";
            U[33] = "session not created";
            U[10] = "stale element reference";
            U[21] = "timeout";
            U[25] = "unable to set cookie";
            U[26] = "unexpected alert open";
            U[13] = Bb;
            U[9] = "unknown command";

            function Cb(a, b) {
                b = b.toLowerCase(); console.log("0000:: __callstack__:" + JSON.stringify(a));
                let ret = "style" == b ? Db(a.style.cssText) : (a = a.getAttributeNode(b)) && a.specified ? a.value : null;
                console.log("1111");
                return ret;
            }
            var Eb = /[;]+(?=(?:(?:[^"]*"){2})*[^"]*$)(?=(?:(?:[^']*'){2})*[^']*$)(?=(?:[^()]*\([^()]*\))*[^()]*$)/;

            function Db(a) {
                var b = [];
                r(a.split(Eb), function(c) {
                    var d = c.indexOf(":");
                    0 < d && (c = [c.slice(0, d), c.slice(d + 1)], 2 == c.length && b.push(c[0].toLowerCase(), ":", c[1], ";"))
                });
                b = b.join("");
                return b = ";" == b.charAt(b.length - 1) ? b : b + ";"
            }

            function Fb(a, b) {
                b && "string" !== typeof b && (b = b.toString());
                return !!a && 1 == a.nodeType && (!b || a.tagName.toUpperCase() == b)
            }

            function Gb(a) {
                return Fb(a, "OPTION") ? !0 : Fb(a, "INPUT") ? (a = a.type.toLowerCase(), "checkbox" == a || "radio" == a) : !1
            };

            function V(a, b, c) {
                this.o = a;
                this.O = b;
                this.P = c
            }
            V.prototype.create = function(a) {
                a = v(a)
                    .createEvent("HTMLEvents");
                a.initEvent(this.o, this.O, this.P);
                return a
            };
            V.prototype.toString = function() {
                return this.o
            };

            function W(a, b, c) {
                n(this, a, b, c)
            }
            m(W, V);
            W.prototype.create = function(a, b) {
                if (this == Hb) throw new Ab(9, "Browser does not support a mouse pixel scroll event.");
                var c = v(a);
                a = c ? c.parentWindow || c.defaultView : window;
                c = c.createEvent("MouseEvents");
                this == Ib && (c.wheelDelta = b.wheelDelta);
                c.initMouseEvent(this.o, this.O, this.P, a, 1, b.clientX, b.clientY, b.clientX, b.clientY, b.ctrlKey, b.altKey, b.shiftKey, b.metaKey, b.button, b.relatedTarget);
                return c
            };

            function Jb(a, b, c) {
                n(this, a, b, c)
            }
            m(Jb, V);
            Jb.prototype.create = function(a, b) {
                a = v(a)
                    .createEvent("Events");
                a.initEvent(this.o, this.O, this.P);
                a.altKey = b.altKey;
                a.ctrlKey = b.ctrlKey;
                a.metaKey = b.metaKey;
                a.shiftKey = b.shiftKey;
                a.keyCode = b.charCode || b.keyCode;
                a.charCode = this == Kb ? a.keyCode : 0;
                return a
            };

            function Lb(a, b, c) {
                n(this, a, b, c)
            }
            m(Lb, V);
            Lb.prototype.create = function(a, b) {
                function c(H) {
                    H = la(H, function(q) {
                        return h.createTouch(l, a, q.identifier, q.pageX, q.pageY, q.screenX, q.screenY)
                    });
                    return h.createTouchList.apply(h, H)
                }

                function d(H) {
                    var q = la(H, function(I) {
                        return {
                            identifier: I.identifier,
                            screenX: I.screenX,
                            screenY: I.screenY,
                            clientX: I.clientX,
                            clientY: I.clientY,
                            pageX: I.pageX,
                            pageY: I.pageY,
                            target: a
                        }
                    });
                    q.item = function(I) {
                        return q[I]
                    };
                    return q
                }

                function e(H) {
                    return la(H, function(q) {
                        return new Touch({
                            identifier: q.identifier,
                            screenX: q.screenX,
                            screenY: q.screenY,
                            clientX: q.clientX,
                            clientY: q.clientY,
                            pageX: q.pageX,
                            pageY: q.pageY,
                            target: a
                        })
                    })
                }

                function f(H, q) {
                    switch (H) {
                        case 1:
                            return d(q);
                        case 2:
                            return c(q);
                        case 3:
                            return e(q)
                    }
                    return null
                }
                var h = v(a),
                    l = h ? h.parentWindow || h.defaultView : window,
                    x = f(1, b.changedTouches),
                    ba = b.touches == b.changedTouches ? x : f(1, b.touches),
                    Na = b.targetTouches == b.changedTouches ? x : f(1, b.targetTouches);
                var O = h.createEvent("MouseEvents");
                O.initMouseEvent(this.o, this.O, this.P, l, 1, 0, 0, b.clientX, b.clientY, b.ctrlKey, b.altKey, b.shiftKey, b.metaKey, 0, b.relatedTarget);
                O.touches = ba;
                O.targetTouches = Na;
                O.changedTouches = x;
                O.scale = b.scale;
                O.rotation = b.rotation;
                return O
            };

            function X(a, b, c) {
                n(this, a, b, c)
            }
            m(X, V);
            X.prototype.create = function() {
                throw new Ab(9, "Browser does not support MSGesture events.");
            };

            function Y(a, b, c) {
                n(this, a, b, c)
            }
            m(Y, V);
            Y.prototype.create = function() {
                throw new Ab(9, "Browser does not support MSPointer events.");
            };
            new W("click", !0, !0);
            new W("contextmenu", !0, !0);
            new W("dblclick", !0, !0);
            new W("mousedown", !0, !0);
            new W("mousemove", !0, !1);
            new W("mouseout", !0, !0);
            new W("mouseover", !0, !0);
            new W("mouseup", !0, !0);
            var Ib = new W("mousewheel", !0, !0),
                Hb = new W("MozMousePixelScroll", !0, !0);
            new Jb("keydown", !0, !0);
            var Kb = new Jb("keypress", !0, !0);
            new Jb("keyup", !0, !0);
            new Lb("touchend", !0, !0);
            new Lb("touchmove", !0, !0);
            new Lb("touchstart", !0, !0);
            new X("MSGestureChange", !0, !0);
            new X("MSGestureEnd", !0, !0);
            new X("MSGestureHold", !0, !0);
            new X("MSGestureStart", !0, !0);
            new X("MSGestureTap", !0, !0);
            new X("MSInertiaStart", !0, !0);
            new Y("MSGotPointerCapture", !0, !1);
            new Y("MSLostPointerCapture", !0, !1);
            new Y("MSPointerCancel", !0, !0);
            new Y("MSPointerDown", !0, !0);
            new Y("MSPointerMove", !0, !0);
            new Y("MSPointerOver", !0, !0);
            new Y("MSPointerOut", !0, !0);
            new Y("MSPointerUp", !0, !0);

            function Mb(a, b) {
                this.D = {};
                this.j = [];
                this.H = 0;
                var c = arguments.length;
                if (1 < c) {
                    if (c % 2) throw Error("Uneven number of arguments");
                    for (var d = 0; d < c; d += 2) this.set(arguments[d], arguments[d + 1])
                } else a && this.addAll(a)
            }

            function Nb(a) {
                Ob(a);
                return a.j.concat()
            }
            g = Mb.prototype;
            g.clear = function() {
                this.D = {};
                this.H = this.j.length = 0
            };
            g.remove = function(a) {
                return Object.prototype.hasOwnProperty.call(this.D, a) ? (delete this.D[a], this.H--, this.j.length > 2 * this.H && Ob(this), !0) : !1
            };

            function Ob(a) {
                if (a.H != a.j.length) {
                    for (var b = 0, c = 0; b < a.j.length;) {
                        var d = a.j[b];
                        Object.prototype.hasOwnProperty.call(a.D, d) && (a.j[c++] = d);
                        b++
                    }
                    a.j.length = c
                }
                if (a.H != a.j.length) {
                    var e = {};
                    for (c = b = 0; b < a.j.length;) d = a.j[b], Object.prototype.hasOwnProperty.call(e, d) || (a.j[c++] = d, e[d] = 1), b++;
                    a.j.length = c
                }
            }
            g.get = function(a, b) {
                return Object.prototype.hasOwnProperty.call(this.D, a) ? this.D[a] : b
            };
            g.set = function(a, b) {
                Object.prototype.hasOwnProperty.call(this.D, a) || (this.H++, this.j.push(a));
                this.D[a] = b
            };
            g.addAll = function(a) {
                if (a instanceof Mb)
                    for (var b = Nb(a), c = 0; c < b.length; c++) this.set(b[c], a.get(b[c]));
                else
                    for (b in a) this.set(b, a[b])
            };
            g.forEach = function(a, b) {
                for (var c = Nb(this), d = 0; d < c.length; d++) {
                    var e = c[d],
                        f = this.get(e);
                    a.call(b, f, e, this)
                }
            };
            g.clone = function() {
                return new Mb(this)
            };
            var Pb = {};

            function Z(a, b, c) {
                ea(a) && (a = a.b);
                a = new Qb(a);
                !b || b in Pb && !c || (Pb[b] = {
                    key: a,
                    shift: !1
                }, c && (Pb[c] = {
                    key: a,
                    shift: !0
                }));
                return a
            }

            function Qb(a) {
                this.code = a
            }
            Z(8);
            Z(9);
            Z(13);
            var Rb = Z(16),
                Sb = Z(17),
                Tb = Z(18);
            Z(19);
            Z(20);
            Z(27);
            Z(32, " ");
            Z(33);
            Z(34);
            Z(35);
            Z(36);
            Z(37);
            Z(38);
            Z(39);
            Z(40);
            Z(44);
            Z(45);
            Z(46);
            Z(48, "0", ")");
            Z(49, "1", "!");
            Z(50, "2", "@");
            Z(51, "3", "#");
            Z(52, "4", "$");
            Z(53, "5", "%");
            Z(54, "6", "^");
            Z(55, "7", "&");
            Z(56, "8", "*");
            Z(57, "9", "(");
            Z(65, "a", "A");
            Z(66, "b", "B");
            Z(67, "c", "C");
            Z(68, "d", "D");
            Z(69, "e", "E");
            Z(70, "f", "F");
            Z(71, "g", "G");
            Z(72, "h", "H");
            Z(73, "i", "I");
            Z(74, "j", "J");
            Z(75, "k", "K");
            Z(76, "l", "L");
            Z(77, "m", "M");
            Z(78, "n", "N");
            Z(79, "o", "O");
            Z(80, "p", "P");
            Z(81, "q", "Q");
            Z(82, "r", "R");
            Z(83, "s", "S");
            Z(84, "t", "T");
            Z(85, "u", "U");
            Z(86, "v", "V");
            Z(87, "w", "W");
            Z(88, "x", "X");
            Z(89, "y", "Y");
            Z(90, "z", "Z");
            var Ub = Z(ta ? {
                c: 91,
                b: 91
            } : sa ? {
                c: 224,
                b: 91
            } : {
                c: 0,
                b: 91
            });
            Z(ta ? {
                c: 92,
                b: 92
            } : sa ? {
                c: 224,
                b: 93
            } : {
                c: 0,
                b: 92
            });
            Z(ta ? {
                c: 93,
                b: 93
            } : sa ? {
                c: 0,
                b: 0
            } : {
                c: 93,
                b: null
            });
            Z({
                c: 96,
                b: 96
            }, "0");
            Z({
                c: 97,
                b: 97
            }, "1");
            Z({
                c: 98,
                b: 98
            }, "2");
            Z({
                c: 99,
                b: 99
            }, "3");
            Z({
                c: 100,
                b: 100
            }, "4");
            Z({
                c: 101,
                b: 101
            }, "5");
            Z({
                c: 102,
                b: 102
            }, "6");
            Z({
                c: 103,
                b: 103
            }, "7");
            Z({
                c: 104,
                b: 104
            }, "8");
            Z({
                c: 105,
                b: 105
            }, "9");
            Z({
                c: 106,
                b: 106
            }, "*");
            Z({
                c: 107,
                b: 107
            }, "+");
            Z({
                c: 109,
                b: 109
            }, "-");
            Z({
                c: 110,
                b: 110
            }, ".");
            Z({
                c: 111,
                b: 111
            }, "/");
            Z(144);
            Z(112);
            Z(113);
            Z(114);
            Z(115);
            Z(116);
            Z(117);
            Z(118);
            Z(119);
            Z(120);
            Z(121);
            Z(122);
            Z(123);
            Z({
                c: 107,
                b: 187
            }, "=", "+");
            Z(108, ",");
            Z({
                c: 109,
                b: 189
            }, "-", "_");
            Z(188, ",", "<");
            Z(190, ".", ">");
            Z(191, "/", "?");
            Z(192, "`", "~");
            Z(219, "[", "{");
            Z(220, "\\", "|");
            Z(221, "]", "}");
            Z({
                c: 59,
                b: 186
            }, ";", ":");
            Z(222, "'", '"');
            var Vb = new Mb;
            Vb.set(1, Rb);
            Vb.set(2, Sb);
            Vb.set(4, Tb);
            Vb.set(8, Ub);
            (function(a) {
                var b = new Mb;
                r(Nb(a), function(c) {
                    b.set(a.get(c)
                        .code, c)
                });
                return b
            })(Vb);
            var Wb = {
                    "class": "className",
                    readonly: "readOnly"
                },
                Xb = "allowfullscreen allowpaymentrequest allowusermedia async autofocus autoplay checked compact complete controls declare default defaultchecked defaultselected defer disabled ended formnovalidate hidden indeterminate iscontenteditable ismap itemscope loop multiple muted nohref nomodule noresize noshade novalidate nowrap open paused playsinline pubdate readonly required reversed scoped seamless seeking selected truespeed typemustmatch willvalidate".split(" ");
            ca("_", function(a, b) {
                var c = b.toLowerCase();
                if ("style" == c) return (b = a.style) && !k(b) && (b = b.cssText), b;
                if (("selected" == c || "checked" == c) && Gb(a)) {
                    if (!Gb(a)) throw new Ab(15, "Element is not selectable");
                    c = "selected";
                    b = a.type && a.type.toLowerCase();
                    if ("checkbox" == b || "radio" == b) c = "checked";
                    return a[c] ? "true" : null
                }
                var d = Fb(a, "A");
                if (Fb(a, "IMG") && "src" == c || d && "href" == c) return (b = Cb(a, c)) && (b = a[c]), b;
                if ("spellcheck" == c) {
                    b = Cb(a, c);
                    if (null !== b) {
                        if ("false" == b.toLowerCase()) return "false";
                        if ("true" == b.toLowerCase()) return "true"
                    }
                    return a[c] +
                        ""
                }
                d = Wb[b] || b;
                if (0 <= ka(Xb, c)) return (b = null !== Cb(a, b) || a[d]) ? "true" : null;
                try {
                    var e = a[d]
                } catch (f) {}
                b = null == e || ea(e) ? Cb(a, b) : e;
                return null != b ? b.toString() : null
            });;
            return this._.apply(null, arguments);
        })
        .apply({
            navigator: typeof window != 'undefined' ? window.navigator : null,
            document: typeof window != 'undefined' ? window.document : null
        }, arguments);
}