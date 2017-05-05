%Homework3 Tianyang Chen
clear all;
I = imread('address.png');
[counts, x] = imhist(I);% Histogram of Grayscale, 'counts' denote the number of pixels 
P=counts./sum(counts);%histogram normalized to sum to 1
mu=x'*P;%calculate the mean of grayscale
n=256;%announce some variable
q1=zeros(256,1);
q2=zeros(256,1);
mu1=zeros(256,1);
mu2=zeros(256,1);
var1=zeros(256,1);
var2=zeros(256,1);
H=zeros(256,1);
pp=find(counts~=0);%find the section that histogram is no 0
first=pp(1);
last=pp(end);
% calculate all the value of q1 & q2
for i=2:n
    q1(i)=q1(i-1)+P(i);
    q2(i)=1-q1(i);
end
q2(1)=1;
%calculate the value of mu1 & mu2
for t=first:last
    sum1=0;
    for j=1:t
        sum1=sum1+x(j)*P(j);
    end
    mu1(t)=sum1/q1(t);
    mu2(t)=(mu-q1(t)*mu1(t))/q2(t); 
end
%calculate the calue of var1 & var2
for t=first:last
    var1(t)=((((0 : (t-1))'-mu1(t)).^2)' * P(1 : t))/q1(t);
    var2(t)=((((t : 255)'-mu2(t)).^2)' * P((t+1) : 256))/q2(t);
end
%compute H(t)    
for t=first:(last-1)
    H(t)=(q1(t)*log(var1(t))+q2(t)*log(var2(t)))./2-q1(t)*log(q1(t))-q2(t)*log(q2(t));
end
%find the minimum of H(t),the corresponding t is the threshold
minH=H(first+1);
for t=(first+1):(last-1)
    if H(t)<minH
        minH=H(t);
    end
end
threshold=find(H==minH);
display(threshold);
%write the bi-level image to the file 'thresholdimg.png'
[row,col]=size(I);
A=zeros(row,col);
for m=1:row
    for n=1:col
        if I(m,n)>=threshold
            A(m,n)=255;
        end
    end
end
Agray = uint8(A);
imwrite(Agray,'thresholdimg.png');
    