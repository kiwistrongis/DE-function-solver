#!/bin/octave -q

datafile = argv(){1};
plotfile = argv(){2};

data = csvread( datafile);

G = data(:,1);
best = data(:,2);
average = data(:,3);
worst = data(:,4);

plot( G, best, '.g', G, average, '-', G, worst, '.r');
xlabel("Generation");
ylabel("Fitness");
print( strcat(plotfile,".png"));
