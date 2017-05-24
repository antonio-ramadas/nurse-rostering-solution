#!/usr/bin/env bash


echo "----------------------------------------------------"
echo "   35 nurses - 4 weeks"
echo "----------------------------------------------------"

SCENARIO="./../datasets/hidden/4-weeks/n035w4/Sc-n035w4.json"

HISTORY="./../datasets/hidden/4-weeks/n035w4/H0-n035w4-0.json"

WEEKS[0]="./../datasets/hidden/4-weeks/n035w4/WD-n035w4-1.json"
WEEKS[1]="./../datasets/hidden/4-weeks/n035w4/WD-n035w4-7.json"
WEEKS[2]="./../datasets/hidden/4-weeks/n035w4/WD-n035w4-1.json"
WEEKS[3]="./../datasets/hidden/4-weeks/n035w4/WD-n035w4-8.json"

SOLVER="./../cmake-build-debug/nrs"

for i in {1..10}
do
    java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
done

echo "----------------------------------------------------"
echo "   35 nurses - 8 weeks"
echo "----------------------------------------------------"

SCENARIO="./../datasets/hidden/8-weeks/n035w8/Sc-n035w8.json"

HISTORY="./../datasets/hidden/8-weeks/n035w8/H0-n035w8-0.json"

WEEKS[0]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-6.json"
WEEKS[1]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-2.json"
WEEKS[2]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-9.json"
WEEKS[3]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-8.json"
WEEKS[4]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-7.json"
WEEKS[5]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-7.json"
WEEKS[6]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-9.json"
WEEKS[7]="./../datasets/hidden/8-weeks/n035w8/WD-n035w8-8.json"

SOLVER="./../cmake-build-debug/nrs"

for i in {1..10}
do
    java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
done

echo "----------------------------------------------------"
echo "   70 nurses - 8 weeks"
echo "----------------------------------------------------"

SCENARIO="./../datasets/hidden/8-weeks/n070w8/Sc-n070w8.json"

HISTORY="./../datasets/hidden/8-weeks/n070w8/H0-n070w8-0.json"

WEEKS[0]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-3.json"
WEEKS[1]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-3.json"
WEEKS[2]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-9.json"
WEEKS[3]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-2.json"
WEEKS[4]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-3.json"
WEEKS[5]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-7.json"
WEEKS[6]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-5.json"
WEEKS[7]="./../datasets/hidden/8-weeks/n070w8/WD-n070w8-2.json"

SOLVER="./../cmake-build-debug/nrs"

for i in {1..10}
do
    java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
done

echo "----------------------------------------------------"
echo "   110 nurses - 8 weeks"
echo "----------------------------------------------------"

SCENARIO="./../datasets/hidden/8-weeks/n110w8/Sc-n110w8.json"

HISTORY="./../datasets/hidden/8-weeks/n110w8/H0-n110w8-0.json"

WEEKS[0]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-8.json"
WEEKS[1]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-5.json"
WEEKS[2]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-7.json"
WEEKS[3]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-3.json"
WEEKS[4]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-9.json"
WEEKS[5]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-8.json"
WEEKS[6]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-8.json"
WEEKS[7]="./../datasets/hidden/8-weeks/n110w8/WD-n110w8-5.json"

SOLVER="./../cmake-build-debug/nrs"

for i in {1..10}
do
    java -jar Simulator_withTimeout.jar --sce $SCENARIO --his $HISTORY --weeks ${WEEKS[*]} --solver $SOLVER
done
