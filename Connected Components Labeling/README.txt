%% if you want to implement 'book.png', then enanble the 1st line and disable the 2nd line. Vise Versa
I = imread('book.png');
I = imread('keys.png');

%% if you want to find 0-pixel components, set fg=0; if you want to find non-0 pixel components, set fg=255
fg=0;

%% if you want to get the output of 'book.png', then enanble the 1st line and disable the 2nd line. Vise Versa
imwrite(Agray,'bookoutput.png');
imwrite(Agray,'keysoutput.png');

Tianyang Chen