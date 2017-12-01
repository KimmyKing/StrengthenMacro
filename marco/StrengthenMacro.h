//
//  StrengthenMacro.h
//  CCFin
//
//  Created by Cain on 2017/11/30.
//  Copyright © 2017年 Goldian. All rights reserved.
//

#ifndef StrengthenMacro_h
#define StrengthenMacro_h

/**
 
 实例:传入三个参数:a, b, c
 JK_Add_SubView(supperView, a, b, c)
 
 #define JK_Prepare_Subviews(supperView, ...)\
 JK_metamacro_foreach(JK_metamacro_foreach, supperView, __VA_ARGS__)
 第一次展开
 JK_metamacro_foreach(JK_metamacro_foreach, supperView, a, b, c)
 
 
 #define JK_metamacro_foreach(Marco, supperView, ...)\
 JK_metamacro_concat(JK_metamacro_foreach, JK_metamacro_argcount(__VA_ARGS__))(Marco, supperView, __VA_ARGS__)
 第二次展开
 JK_metamacro_concat(JK_metamacro_foreach, JK_metamacro_argcount(a, b, c))(JK_Add_Subview, supperView, a, b, c)
 
 参数中的宏展开
 #define JK_metamacro_argcount(...) \
 JK_metamacro_at(20, a, b, c, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
 
 #define JK_metamacro_at(N, ...) \
 JK_metamacro_concat_(JK_metamacro_at, 20)(a, b, c, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
 
 截取之后就剩下了3, 2, 1  {_0 ~ _19这20个参数(a, b, c, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4)在这边没有传递到下一个宏中}
 #define JK_metamacro_at20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) JK_metamacro_head(3, 2, 1)
 
 #define JK_metamacro_head(...) \
 JK_metamacro_head_(3, 2, 1, 0)
 
 得到结果: 参数个数
 #define JK_metamacro_head_(FIRST, ...) 3
 
 #define JK_metamacro_concat(A, B) \
 JK_metamacro_concat_(A, B)
 第三次展开
 JK_metamacro_concat_(JK_metamacro_foreach, 3)(JK_Add_Subview, supperView, a, b, c)
 
 
 #define JK_metamacro_concat_(A, B) A ## B      //拼接宏,结果为AB
 第四次展开
 JK_metamacro_foreach3(JK_Add_Subview, supperView, a, b, c)
 
 
 #define JK_metamacro_foreach3(Marco, Parameter, _0, _1, _2)\
 JK_metamacro_foreach2(Marco, Parameter, _0, _1)\
 Marco(Parameter, _2, 2)
 第五次展开
 JK_metamacro_foreach2(JK_Add_Subview, supperView, a, b)
 JK_Add_Subview(supperView, c)
 
 
 #define JK_metamacro_foreach2(Marco, Parameter, _0, _1)\
 JK_metamacro_foreach1(Marco, Parameter, _0)\
 Marco(Parameter, _1, 1)
 第六次展开
 JK_metamacro_foreach1(JK_Add_Subview, supperView, a)
 JK_Add_Subview(supperView, b)
 JK_Add_Subview(supperView, c)
 
 
 第七次展开
 JK_Add_Subview(supperView, a)
 JK_Add_Subview(supperView, b)
 JK_Add_Subview(supperView, c)
 
 */



/**
 传入N个(N<=20)子视图添加到supperView上
 
 @param supperView 父视图
 @param ... N个子视图
 */
#define JK_Prepare_Subviews(supperView, ...)\
JK_metamacro_foreach(JK_Add_Subview, supperView, __VA_ARGS__)

#define JK_metamacro_foreach(Marco, supperView, ...)\
JK_metamacro_concat(JK_metamacro_foreach, JK_metamacro_argcount(__VA_ARGS__))(Marco, supperView, __VA_ARGS__)

#define JK_metamacro_foreach20(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)\
JK_metamacro_foreach19(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)\
Marco(Parameter, _19, 19)

#define JK_metamacro_foreach19(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)\
JK_metamacro_foreach18(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)\
Marco(Parameter, _18, 18)

#define JK_metamacro_foreach18(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)\
JK_metamacro_foreach17(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)\
Marco(Parameter, _17, 17)

#define JK_metamacro_foreach17(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)\
JK_metamacro_foreach16(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)\
Marco(Parameter, _16, 16)

#define JK_metamacro_foreach16(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)\
JK_metamacro_foreach15(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)\
Marco(Parameter, _15, 15)

#define JK_metamacro_foreach15(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)\
JK_metamacro_foreach14(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)\
Marco(Parameter, _14, 14)

#define JK_metamacro_foreach14(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)\
JK_metamacro_foreach13(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)\
Marco(Parameter, _13, 13)

#define JK_metamacro_foreach13(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)\
JK_metamacro_foreach12(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)\
Marco(Parameter, _12, 12)

#define JK_metamacro_foreach12(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)\
JK_metamacro_foreach11(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10)\
Marco(Parameter, _11, 11)

#define JK_metamacro_foreach11(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10)\
JK_metamacro_foreach10(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9)\
Marco(Parameter, _10, 10)

#define JK_metamacro_foreach10(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9)\
JK_metamacro_foreach9(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8)\
Marco(Parameter, _9, 9)

#define JK_metamacro_foreach9(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7, _8)\
JK_metamacro_foreach8(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7)\
Marco(Parameter, _8, 8)

#define JK_metamacro_foreach8(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6, _7)\
JK_metamacro_foreach7(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6)\
Marco(Parameter, _7, 7)

#define JK_metamacro_foreach7(Marco, Parameter, _0, _1, _2, _3, _4, _5, _6)\
JK_metamacro_foreach6(Marco, Parameter, _0, _1, _2, _3, _4, _5)\
Marco(Parameter, _6, 6)

#define JK_metamacro_foreach6(Marco, Parameter, _0, _1, _2, _3, _4, _5)\
JK_metamacro_foreach5(Marco, Parameter, _0, _1, _2, _3, _4)\
Marco(Parameter, _5, 5)

#define JK_metamacro_foreach5(Marco, Parameter, _0, _1, _2, _3, _4)\
JK_metamacro_foreach4(Marco, Parameter, _0, _1, _2, _3)\
Marco(Parameter, _4, 4)

#define JK_metamacro_foreach4(Marco, Parameter, _0, _1, _2, _3)\
JK_metamacro_foreach3(Marco, Parameter, _0, _1, _2)\
Marco(Parameter, _3, 3)

#define JK_metamacro_foreach3(Marco, Parameter, _0, _1, _2)\
JK_metamacro_foreach2(Marco, Parameter, _0, _1)\
Marco(Parameter, _2, 2)

#define JK_metamacro_foreach2(Marco, Parameter, _0, _1)\
JK_metamacro_foreach1(Marco, Parameter, _0)\
Marco(Parameter, _1, 1)

#define JK_metamacro_foreach1(Marco, Parameter, _0)\
Marco(Parameter, _0, 0)

#define JK_Add_Subview(supperView, suberView, Index)\
[supperView addSubview:suberView];

#define JK_metamacro_concat(A, B) \
JK_metamacro_concat_(A, B)

#define JK_metamacro_concat_(A, B) A ## B //表示连接A和B,结果是AB

//传入N个参数,获得参数的个数: N
#define JK_metamacro_argcount(...) \
JK_metamacro_at(20, __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define JK_metamacro_at(N, ...) \
JK_metamacro_concat_(JK_metamacro_at, 20)(__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define JK_metamacro_at20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) JK_metamacro_head(__VA_ARGS__)

#define JK_metamacro_head(...) \
JK_metamacro_head_(__VA_ARGS__, 0)

//得到结果: 参数个数
#define JK_metamacro_head_(FIRST, ...) FIRST

#endif /* StrengthenMacro_h */

