import os

MAX_COUNT = 22

def replace(name, val):
    s = ''
    with open('demo.html', 'r') as fin:
        s = fin.read()
    res = ''
    if type(val) == list:
        res = ', '.join([str(x) for x in val])
    else:
        res = str(val)
    s = s.replace('/*--' + name + '--*/', res)
    with open('demo.html', 'w') as fout:
        fout.write(s)

def handle(sort_type):
    vals = []
    for i in range(1, MAX_COUNT + 1):
        try:
            with open('../log/test_' + sort_type + '_' + str(i) + '.log') as f:
                line = f.readlines()[1]
                vals.append(int(float(line.split(' ')[-1]) * 1000))
        except FileNotFoundError:
            break
    replace(sort_type + '.data', vals)

def main():
    os.system('cp template.html demo.html')
    replace('xAxis.data', list(range(1, MAX_COUNT + 1)))
    handle('bubble')
    handle('std')
    handle('quick')

main()