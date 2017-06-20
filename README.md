# Nurse Rostering Solution

As a project for [Methodologies for Planning and Scheduling](https://paginas.fe.up.pt/~eol/PRODEI/mpe1617_eng.htm) it has been developed an attempt to solve the widely known Nurse Rostering Problem as stated in [The Second International Nurse Rostering Competition](http://mobiz.vives.be/inrc2/). A paper detailing the approach has also been produced. The working group chose C++ as the programming language due to its versatility.

External libraries:
 - [JSON for Modern C++ Version 2.1.1](https://github.com/nlohmann/json)
 
## How to run
For simplicity you may just execute [run.sh](tools/run.sh). However, this solver follows the [guidelines from INRC-II](INRC2.pdf). Please, take a look at them before editing and executing the script.
  
## Development
This program has been made with [CLion](https://www.jetbrains.com/clion/) and, to be easier to develop, here is a working example of the arguments:
```
--sce "./../datasets/test/n005w4/Sc-n005w4.json" --his "./../datasets/test/n005w4/H0-n005w4-0.json" --week "./../datasets/test/n005w4/WD-n005w4-0.json" --sol "./../output/sol-week0.json"
```

## Proposed Solution
A paper has been produced detailing the implementation and may be consulted [here](A%20GRASP%20Approach%20using%20a%20Constructive%20Heuristic%20Approach%20to%20the%20Nurse%20Scheduling%20Problem.pdf).