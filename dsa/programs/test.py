import json
f = open('example_1.json',)
data = json.load(f)
for i in data['emp_details']:
    print(i['emp_name'])
f.close()