# approximating z(x,y)= e^((-1/x^2+y^2+2)*cos(xy)*20)
# max = 3
import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import numpy as np
import tensorflow.keras
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import Adam, RMSprop
from sklearn.model_selection import train_test_split
from sklearn.metrics import max_error, mean_absolute_error

dots = 10000

x = np.linspace(-3, 3, dots)
y = np.linspace(-3, 3, dots)
z = np.exp((-1/(x**2+y**2+2))*np.cos(x*y)*20)

x_train, x_test, y_train, y_test, z_train, z_test = train_test_split(x, y, z, train_size=0.6)
x_test, x_val, y_test, y_val, z_test, z_val = train_test_split(x_test, y_test, z_test, train_size=0.5)
xy_train = np.array((x_train, y_train)).T
xy_test = np.array((x_test, y_test)).T
xy_val = np.array((x_val, y_val)).T
n = 10
model = tensorflow.keras.Sequential(
    [tensorflow.keras.Input(shape=(2,)),
     Dense(units=n, activation='tanh'), #слои 
     Dense(units=1, activation='linear')])
model.compile(optimizer=RMSprop(0.01), loss='mean_absolute_error') # RMSprop - метод оптимизации град. спуска, loss - погрешность (различие обучаемых знач. от реальных) здесь средн€€ абсолютна€ ошибка
foo = model.fit(xy_train, z_train, validation_data=(xy_val, z_val), epochs=55, verbose=1)

z_pred = model.predict(xy_test)
maxim_error = max_error(z_test, z_pred)
mean_error = mean_absolute_error(z_test, z_pred)
maxim = np.max(z) / 10
print(mean_error)
print(maxim_error)
print(maxim)

k = 0
for i in range(len(z_pred)):
    if abs(z_test[i] - z_pred[i]) < maxim:
        k += 1
if k != 0:
    percentage = (k / len(z_pred)) * 100
else:
    percentage = 100
print(percentage)

plt.plot(foo.history['loss'])
plt.plot(foo.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'val'], loc='upper right')
plt.show()
