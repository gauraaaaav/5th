img = imread('flower.jpg');   
img = im2double(img);
noise_density = 0.3;  
noisy_img = imnoise(img, 'salt & pepper', noise_density);
figure;
subplot(1,2,1);
imshow(img);
title('Original Grayscale Image');

subplot(1,2,2);
imshow(noisy_img);
title('Salt & Pepper Noisy Image');
