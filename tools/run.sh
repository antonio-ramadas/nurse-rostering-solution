#!/usr/bin/env bash

SCENARIO="./../datasets/test/n005w4/Sc-n005w4.json"

HISTORY="./../datasets/test/n005w4/H0-n005w4-0.json"

WEEKS[0]="./../datasets/test/n005w4/WD-n005w4-0.json"
WEEKS[1]="./../datasets/test/n005w4/WD-n005w4-1.json"
WEEKS[2]="./../datasets/test/n005w4/WD-n005w4-2.json"
WEEKS[3]="./../datasets/test/n005w4/WD-n005w4-3.json"

SOLVER="./../cmake-build-debug/nrs"

java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
