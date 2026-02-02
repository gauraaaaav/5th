img = imread('dog.jpg'); 
img = im2double(img);
mean_noise = 0;
sigma = 0.05;   
noise = mean_noise + sigma * randn(size(img));
noisy_img = img + noise;
noisy_img = min(max(noisy_img, 0), 1);
figure;
subplot(1,2,1);
imshow(img);
title('Original Grayscale Image');

subplot(1,2,2);
imshow(noisy_img);
title('Image with Gaussian Noise');
