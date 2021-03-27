import os

MIN_COUNT = 10
MAX_COUNT = 22

def replace(name, val):
    s = ''
    with open('demo.html', 'r') as fin:
        s = fin.read()
    if type(val) == range:
        val = list(val)
    if type(val) == list:
        val = ', '.join([str(x) for x in val])
    val = str(val)
    s = s.replace('/*--' + name + '--*/', val)
    with open('demo.html', 'w') as fout:
        fout.write(s)

def handle(sort_type):
    vals = []
    for i in range(MIN_COUNT, MAX_COUNT + 1):
        try:
            with open('../log/test_' + sort_type + '_' + str(i) + '.log') as f:
                line = f.readlines()[1]
                vals.append(int(float(line.split(' ')[-1]) * 1000))
        except FileNotFoundError:
            break
    replace(sort_type + '.data', vals)

def main():
    os.system('cp template.html demo.html')
    replace('xAxis.data', range(MIN_COUNT, MAX_COUNT + 1))
    handle('bubble')
    handle('std')
    handle('quick')

main()