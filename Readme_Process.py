all_text = open('./README.md').read()
test_n = 0
while (all_text.find('##') != -1):
    test_n += 1
    st = all_text.find('##')
    ed = all_text.find('##',st+1)
    if (ed == -1):
        ed = len(all_text)
    cur_text = all_text[st:ed]

    filename = cur_text[3:6]

    with open('./Insights/' + filename+'.md','w') as f:
        f.write(cur_text)
    all_text = all_text[ed:]
    #print(all_text[:20])
    #print('----------------------------------------------------------------')
