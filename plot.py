import pandas as pd
import numpy as np 
from matplotlib import pyplot as plt 
from matplotlib import animation 
 
fig = plt.figure() 
ax = plt.axes(xlim=(0, 200), ylim=(0, 200)) 
line, = ax.plot([], [], lw=2) 
def init(): 
    line.set_data([], []) 
    return line, 
 

df = pd.read_csv("streps.csv") 
size = df.shape[1] -1 
size =int(size/ 2) 

hist_size = min(100000,df.shape[0] )
histo_dist = np.zeros(hist_size)

print(size) 
y = np.zeros(size)  
x = np.zeros(size)  
# animation function.  This is called sequentially 
def animate(i): 
    if i% 100 == 0: 
        print(i) 
    row = df.iloc[i] 

    deltax = row["x0"] - row["x{}".format(size-1)]
    deltay = row["y0"] -row["y{}".format(size-1)]
    #
    histo_dist[i] = np.sqrt(deltax**2 + deltay**2)
    for k in range(size): 
        x[k] = row["x{}".format(k)] 
        y[k] = row["y{}".format(k)] 
    
    line.set_data(x, y) 
    return line, 
 

for i in range(hist_size):
    row = df.iloc[i] 

    deltax = row["x0"] - row["x{}".format(size-1)]
    deltay = row["y0"] - row["y{}".format(size-1)]
    #
    histo_dist[i] = np.sqrt(deltax**2 + deltay**2)
# call the animator.  blit=True means only re-draw the parts that have changed. 
# anim = animation.FuncAnimation(fig, animate, init_func=init, repeat=False,
#                                frames=df.shape[0], interval=1, blit=True) 

# plt.show()  
plt.clf()
plt.hist(histo_dist, bins = 100)
                            
plt.show()  



import matplotlib.pyplot as plt  
from worm_simulation import worm_simulation  
from matplotlib import animation  
import numpy as np 
 
gx = 100 
nworm = 50 
nframe =int( 1e9)
incr = int(1e5)
sim = worm_simulation(nworm,gx,gx)  
result = sim.run(nframe, incr,False)  
result_swapped = result.swapaxes(1,2)  
def init():  
    line.set_data([], [])  
    return line, 
     
def animate(i):  
    x = result_swapped[i][0]  
    y = result_swapped[i][1]  
    #print(x) 
    line.set_data(x, y)  
    return line, 
     

fig = plt.figure()  
ax = plt.axes(xlim=(0, gx), ylim=(0, gx))  
line, = ax.plot([], [], lw=2)  
anim = animation.FuncAnimation(fig, animate, init_func=init, repeat=False,   frames=result.shape[0], interval=1, blit=True)  
plt.show() 




hist = np.zeros((result.shape[0]))  

for i in range(result.shape[0]): 
    x = result_swapped[i][0] 
    y = result_swapped[i][1] 
    hist[i] = np.sqrt( (x[0]-x[nworm-1]) * (x[0]-x[nworm-1]) + (y[0]-y[nworm-1]) * (y[0]-y[nworm-1]))  
plt.hist(hist,bins =100, density = True, color  = "C0", alpha = 0.5) 