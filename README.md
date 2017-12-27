---
title:  实现字符串类MyString
tags: c++,string
grammar_cjkRuby: true
---
# 实现字符串类MyString
设记一个简单的字符市类MyString,它包含设置字符串、返回字符申长度和显示内容等功花能
对字符中进行插入.替换、删除、查找和连接等探作。
## 程序要求 :
1) 对字符中的深作采用下列菜单形式:
* 生成字符串
* 显示
* 求字符串长度
* 字符申插入
* 字符串替换
* 字符串删除
* 字符串的连接
* 返回


2) 调试
* 生成字符中s="ABCDBCEFGHTH"
* 求长度len(s)=12
* 符中的插入t=*XYZ"

   insert(s,3 t)=“ABXYZCDBCEFGHTH"
   
* 字符串的替换，将字符串中所有p="BC"替换为t="LMN";

   repl(s p.t)="ALMNDLMNEFGHTH"
   
* 字符串的查找 p="BC":

    index(s,p)=2
	
* 字符串的连接将亨符串p=“12345678" 的宁符串s 连接:
 
    strcat(s,p)="ABCDBCEFGHTH12345678"
