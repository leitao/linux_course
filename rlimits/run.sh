#!/bin/bash

time prlimit --cpu=10 ./loop_forever
prlimit --core=unlimited ./loop_forever illegal


