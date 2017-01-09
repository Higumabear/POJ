# -*- coding: utf-8 -*-
import requests
import re

my_url = 'http://poj.org/userstatus?user_id=4dtv'
my_text = requests.get(my_url).text
my_re = re.compile('\(\d{4}\)')
my_solved_num = [x[1:-1] for x in my_re.findall(my_text)]
#print(my_solved_num)

while True:
    print('比較するページのURLを入力してください')
    target_url = input()
    target_text = requests.get(target_url).text
    target_re = re.compile('<a href=problem\?id=\d{4}>\d{4}');
    target_solved_num = [x[-4:] for x in target_re.findall(target_text)]

    for x in sorted(target_solved_num):
        if not x in my_solved_num:
            print("------------------------------------------------")
            print("| " + x + " |  http://poj.org/problem?id=" + x)
    print("------------------------------------------------")
    print('表示完了しました')
# print(target_solved_num)
# print(len(target_solved_num))
