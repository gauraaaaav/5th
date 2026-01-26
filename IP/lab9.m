clear all; % clear all variables
close all; % close all figures
clc;       % clear command window
% import image package
pkg load image;
% read image
l = im2double(imread('dogs.jpg'));
f1 = fft(l);
f2 = fftshift(f1);
subplot(2,2,1); imshow(abs(f1)); title('Frequency Spectrum');
subplot(2,2,2); imshow(abs(f2)); title('Centered Spectrum');
f3 = log(1+abs(f2));
subplot(2,2,3); imshow(f3); title('log(1+abs(f2))');
l = ifft2(f1);
ll = real(l);
subplot(2,2,4); imshow(ll); title(' 2-D FFT');
