clc, clear all

% Reading in data from excel file
x = xlsread('steering_torque.xlsx');
[m n] =  size(x);

kp100 = x(:,1);
kp10 = x(:,2);
kp1 = x(:,3);
kp20 = x(:,4);
kp7 = x(:,5);
kp200 = x(:,6);

% Plotting the different gain rates 
figure(1)
hold on
plot(1:m, x(:,3))
plot(1:m, x(:,5))
plot(1:m, x(:,2))
plot(1:m, x(:,4))
plot(1:m, x(:,1))
plot(1:m, x(:,6))

xlabel('Sample Number')
ylabel('Steering Torque')
legend('1','7','10','20','100','200')


% Adding text on plot that shows mean and standard deviation of data
str1 = strcat('Kp = 1','        mean: ',num2str(nanmean(kp1)),'     std: ',num2str(nanstd(kp1)));
str7 = strcat('Kp = 7','        mean: ',num2str(nanmean(kp7)),'       std: ',num2str(nanstd(kp7)));
str10 = strcat('Kp = 10','      mean: ',num2str(nanmean(kp10)),'     std: ',num2str(nanstd(kp10)));
str20 = strcat('Kp = 20','      mean: ',num2str(nanmean(kp20)),'     std: ',num2str(nanstd(kp20)));
str100 = strcat('Kp = 100','    mean: ',num2str(nanmean(kp100)),'   std: ',num2str(nanstd(kp100)));
str200 = strcat('Kp = 200','    mean: ',num2str(nanmean(kp200)),'   std: ',num2str(nanstd(kp200)));

text(200,-2000,str1)
text(200,-2350,str7)
text(200,-2700,str10)
text(200,-3050,str20)
text(200,-3400,str100)
text(200,-3750,str200)
hold off

