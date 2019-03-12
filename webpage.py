import pickle
from flask import Flask
app = Flask(__name__)

@app.route('/')
def display_process_data():
    html = ''
    with open('process_data.pkl', 'rb') as f:
        process_data = pickle.load(f)
    num_process = process_data['number_of_processes']
    processes = process_data['processes_info']

    html = html + '<h1>Number of processes running currently are ' + str(num_process) + '</h1>\n\n'
    html = html + '''<table border=2>
    <thead>
        <tr>
            <th>Process ID</th>
            <th>Time running</th>
            <th style="text-align: left;">Process name</th>
        </tr>
    </thead>
    <tbody>'''

    all_rows = ''
    for i in range(len(processes)-1,0,-1):
        row_value = '<tr><th>' + str(processes[i]['process_id']) + '</th><th>' + str(processes[i]['process_time']) + '</th><th style="text-align: left;">' + str(processes[i]['name_of_process']) + '</th></tr>'
        all_rows += row_value

    html = html + all_rows

    html = html + '''
    </tbody>
    </table>'''
    return html

if __name__ == '__main__':
  app.run(host='0.0.0.0',debug=True)
