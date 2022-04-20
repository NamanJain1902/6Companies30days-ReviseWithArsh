import os
import sys
# import requests
# from bs4 import BeautifulSoup
# from selenium import webdriver
# import time 

filename = sys.argv[1]


# if len(sys.argv) > 2:
    
#     if sys.argv[1] == '-f':
#         url = sys.argv[2]
#         # browser = webdriver
#         # browser.get(url)
#         # html = browser.page_source
#         # soup = BeautifulSoup(html, 'lxml')
#         r = requests.get(url, timeout=(3.05, 27))
#         # time.sleep(5)
#         content = r.content
#         soup = BeautifulSoup(content, 'html.parser')
#         # print(soup.prettify())
#         # print(soup.find(attrs={"class" : 'CodeMirror-code'}))
#         print(soup.find('div', attrs={'class': 'ace_content'}))
#         # print(r.json())
#         # print(soup.title)
#         # print(soup.get_text())
#         # print(r.status_code)
#         # print(r.content)
        

os.makedirs(filename)

with open(os.path.join(filename, filename + '.cc'), 'w') as f:
    data = """
#include<bits/stdc++.h>
using namespace std;






int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol. << endl;
    return 0;
}
    """
    f.write(data)
    pass

with open(os.path.join(filename, "notes" + '.md'), 'w') as f:
    pass
