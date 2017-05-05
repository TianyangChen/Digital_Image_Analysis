%Homework2 Tianyang Chen
clc;clear;close all
f=imread('edges.png');
[row,col]=size(f);
diag=round((row*row+col*col)^0.5);
A=zeros(100,100);% Set the Hough Array Matrix

for m=1:row
    for n=1:col
        if f(m,n)>0
            for thera=1:90%scale thera to [0,90](less than 100)
                r=2*thera/180*pi;%degree to radian
                %let origin be at the center of edgemap
                x=n-128;
                y=122-m;
                rr=x*cos(r)+y*sin(r);%¦Ñ=x(i)cos(¦È)+y(i)sin(¦È)
                rho=round((rr+diag/2)/3.5);%scale rho to [0,100]
                A(rho,thera)=A(rho,thera)+1;
            end
        end
    end
end
%scale hough array to [0,255]
coe=255/(max(max(A)));
Agray = uint8(coe*A);
imwrite(Agray,'HoughArray.png');%write the grayscale hough array image

threshold=138;%set the threshold
[rho,thera]=find(Agray>threshold);
nrho=length(rho);
%draw the lines that were detected by hough transform
imshow(f);
for i=1:nrho
    hold on
    n=1:col;
    r=2*thera(i)/180*pi;
    m = 122 - (rho(i)*3.5-diag/2-(n-128)*cos(r))/sin(r);    
    plot(n,m,'r');
end
