import subprocess
import pickle
import time
from copy import deepcopy

def write_process():
    response = subprocess.check_output(['ps','aux'])
    response = str(response)
    processes = response.split('\\n')
    processes = processes[1:-1]

    num_of_processes = len(processes)
    # print(num_of_processes)
    process_json = {'name_of_process':'','process_id':'','process_time':''}
    all_processes = []
    for process in processes:
        row_json = deepcopy(process_json)
        li = process.split()
        pid = li[1]
        time = li[9]
        name = ''.join(li[10:])
        row_json['name_of_process'] = name
        row_json['process_id'] = pid
        row_json['process_time'] = time
        all_processes.append(row_json)

    process_data = {'number_of_processes': num_of_processes,
                   'processes_info':all_processes}

    with open('process_data.pkl', 'wb') as f:
        pickle.dump(process_data, f, pickle.HIGHEST_PROTOCOL)

    return

def main():
    while(1):
        write_process()
        time.sleep(10)

main()
