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

## Interface
The interface serves as a Graphical User Interface of the solver. It has been developed with ECMAScript 6 and ESLint. In order to run, the following command must be executed inside the interface folder:
```
npm run dev
```

This aplication consists in a simple GUI wich dinamically parses the output of the C++ algorithm, properly presenting the rostering of the nurses.
It uses Electron with VueJS, producing a desktop app with a simple UI to observe the results.
