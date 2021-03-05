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

aline = '|'
insights = os.walk('./Insights')

for path,dir_list,file_list in insights:
    for file_name in file_list:
        #print(file_name)
        number = 0 # xxx.md
        if file_name.find('.md') != -1:
            number = file_name[:3]
        problem_name = ''
        problem_link = ''
        Difficulty = ''
        
        language = ''
        language_type = ''
        language_link = './Scripts/' + str(number) + '.' + language_type

        type = 'TBC...'

        
        aline += str(number) + '| [' + problem_name + '](' + problem_link + ') | [' + language + '](' + language_link + ') | [' + type + '](./Insights/' + number + '.md) | ' + Difficulty

        print(aline)

