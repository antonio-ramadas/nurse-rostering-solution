#!/usr/bin/env bash

SCENARIO="./../datasets/competition/n030w4/Sc-n030w4.json"

HISTORY="./../datasets/competition/n030w4/H0-n030w4-0.json"

WEEKS[0]="./../datasets/competition/n030w4/WD-n030w4-6.json"
WEEKS[1]="./../datasets/competition/n030w4/WD-n030w4-7.json"
WEEKS[2]="./../datasets/competition/n030w4/WD-n030w4-5.json"
WEEKS[3]="./../datasets/competition/n030w4/WD-n030w4-3.json"

SOLVER="./../cmake-build-debug/nrs"

java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
