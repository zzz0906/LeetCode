# all_text = open('./README.md').read()
# test_n = 0
# while (all_text.find('##') != -1):
#     test_n += 1
#     st = all_text.find('##')
#     ed = all_text.find('##',st+1)
#     if (ed == -1):
#         ed = len(all_text)
#     cur_text = all_text[st:ed]

#     filename = cur_text[3:6]

#     with open('./Insights/' + filename+'.md','w') as f:
#         f.write(cur_text)
#     all_text = all_text[ed:]
#     #print(all_text[:20])
#     #print('----------------------------------------------------------------')


# ----------------------------------------------------------------
# Generate the table in readme
# ----------------------------------------------------------------

# |318| [Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/) | [C++](./Scripts/318.cpp)|[Brute Force](./Insights/318.md)| Medium
import os
import requests
import json

insights = os.walk('./Insights')

r = requests.get('https://leetcode.com/api/problems/all/',headers={'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 11_2_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.192 Safari/537.36','cookie':'_ga=GA1.2.1212593041.1582447157; csrftoken=wWRM4kM6FgnXrgIQdce9ILIla9GVfWUHjsARzVAhFexIu534Mcrs8tt6lmdHgjlp; __stripe_mid=f4954de5-917c-4f31-a476-666d43ba3fa912e19f; cf_clearance=601c41885ff3fa196183ac1c4950f7f4710603cb-1608663920-0-150; __cfduid=d91a4bad0616d427fcb0f3ca05398f8b61614483629; _gid=GA1.2.1414716581.1615185849; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiNjYxNTQyIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJmMGFkOTk3MjNkZmRiOTExZDgzODcxMTk2Yjc2MTI5NTA1MDg5ZWQxIiwiaWQiOjY2MTU0MiwiZW1haWwiOiI1MjYzMzQyNzdAcXEuY29tIiwidXNlcm5hbWUiOiJaaG91ZWVlciIsInVzZXJfc2x1ZyI6Inpob3VlZWVyIiwiYXZhdGFyIjoiaHR0cHM6Ly93d3cuZ3JhdmF0YXIuY29tL2F2YXRhci9jYjcyMjA5MWRkYjMxMGE0OTRiOTMwYTlhNmQ4MDhiZS5wbmc_cz0yMDAiLCJ0aW1lc3RhbXAiOiIyMDIwLTA0LTIxIDA0OjU5OjE1LjkzMDQzNCswMDowMCIsIklQIjoiMjE4LjI1MC4yNDAuNDgiLCJJREVOVElUWSI6IjEzMzM0NDM5ZDQ2OWRkM2RhZTViYzJjZDU4MGI0MzBiIiwiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwLCJpcCI6IjI0MDQ6YzgwMTo5OTM6ODNmODo5Y2Y2OjlkZmY6ZmViMDplMjQwIiwiaWRlbnRpdHkiOiIxMzMzNDQzOWQ0NjlkZDNkYWU1YmMyY2Q1ODBiNDMwYiIsInJlZnJlc2hlZF9hdCI6MTYxNTE4NTg0OCwic2Vzc2lvbl9pZCI6MjIxNDc3fQ.QfGzA3P29J_BIPPyGCUZx2MmHPqZ_8kejDv-DZf2fIU; __cf_bm=23c115c00392734b540cc1ccd494a6b4b952eae3-1615273910-1800-AZ3wbX337iIZPRvc5F7yJOon9zTp5QGvUZL794FNNxFUVr3ohXFxGCPPugo5KhkyflwQ+72PO5ajUQi0a2hT+R4=; __atuvc=0|6,0|7,0|8,2|9,1|10; __atuvs=60471fc17abc1b5f000; c_a_u=\"WmhvdWVlZXI=:1lJWfK:ALergJEbvRykY6ajU0b5bkidUXY\"'})
content = r.content
content_json = json.loads(content)

# file = open('test.html', mode='w')
# file.write(content)
# file.close()
dif = {1:'Easy',2:'Medium',3:'Hard'}
def find_name_and_link_and_difficulty(number):
    return content_json['stat_status_pairs'][1787-number]['stat']['question__title'],'https://leetcode.com/problems/' + content_json['stat_status_pairs'][1787-number]['stat']['question__title_slug'],dif[content_json['stat_status_pairs'][1787-number]['difficulty']['level']]


f = open("Readme_Auto.md", "w")

for path,dir_list,file_list in insights:
    
    # find all numbers in insights
    numbers = []
    for file_name in file_list:
        #print(file_name)
        number = -1 # xxx.md
        if file_name.find('.md') != -1:
            number = file_name[:file_name.find('.md')]
        
        if (number == -1):
            continue
        
        numbers.append(int(number))
    numbers.sort()
    
    # print(numbers)
    
    # find all code file
    scripts = os.walk('./Scripts')
    codes = []
    
    for path,dir_list,file_list in scripts:
        for file_name in file_list:
            codes.append(file_name)

    for number in numbers:

        aline = '|'


        problem_name , problem_link, Difficulty = find_name_and_link_and_difficulty(int(number))

        language = ''
        language_type = ''
        for code in codes:
            if code.find(str(number)) != -1 and code.find('.') != -1:
                language_type = code[code.find('.'):]
                language = language_type[1:].upper()
                break

        if (language =='CPP'):
            language = 'C++'
        
        language_link = './Scripts/' + str(number) + '.' + language_type

        type = 'TBC...'

        
        aline += str(number) + '| [' + problem_name + '](' + problem_link + ') | [' + language + '](' + language_link + ') | [' + type + '](./Insights/' + str(number) + '.md) | ' + Difficulty

        #print(aline)
        f.write(aline + '\n')

f.close()

