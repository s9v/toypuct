#!/bin/bash
while python3 stressgen.py >gen_tmp.txt && diff <(./solution <gen_tmp.txt) <(python3 bruteforce.py <gen_tmp.txt); do echo PASS; sleep 0.3; done;
