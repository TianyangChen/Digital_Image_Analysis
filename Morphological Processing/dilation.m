function out1=dilation(varargin)
% Tianyang Chen
% function dilation(varargin) perform dilation on binary image
% ================================================================
% out1=dilation(InputImage,OutputImage,fg,SE_width)
% ================================================================
%  InputImage - the file name of input image
% OutputImage - the file name of output image
%          fg - this parameter has two values: 
%               0   denotes black region is the foreground
%               255 denotes white region is the foreground
%    SE_width - the width (an odd number) of the structuring element
% ================================================================
% Example:
% dilation('morph.png','AdB.png',0,11)
% ================================================================
img=imread(varargin{1});
fg=varargin{3};
SE_width=varargin{4};
% check the parameter, make sure the user type the right parameter
if fg~=0 && fg~=255
    error('Valid foreground value is 0 and 255');
end
if rem(SE_width,2)~=1||SE_width<=0
    error('Valid structuring element width should be a positive odd number');
end

half_width=(SE_width-1)/2;
[row,col]=size(img);
img_expand=(255-fg)*ones((row+2*half_width),(col+2*half_width));% expand the image by SE_width on both row and col, just for convenience of compare each pixel
out_img=(255-fg)*ones(row,col);% set the output image matrix to background
for r=1:row
    for c=1:col
        img_expand((r+half_width),(c+half_width))=img(r,c);
    end
end

for r=(1+half_width):(row+half_width)% move the SE along the input image
    for c=(1+half_width):(col+half_width)
        check_matrix=reshape(img_expand((r-half_width):(r+half_width),(c-half_width):(c+half_width)),1,(SE_width*SE_width));
        for i=1:(SE_width*SE_width)% check the pixels of input image in SE region
            if check_matrix(i)==fg% If at least one pixel is foreground
                out_img(r-half_width,c-half_width)=fg;% set the corresponding pixel in output image to foreground
                break;
            end
        end
    end
end
% write the output image                     
imwrite(out_img,varargin{2});    
end