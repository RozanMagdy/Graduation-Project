from math import*
import random 


class robot:
	def__init__(self):
		self.x = random.random()* world_size
		self.y = random.random()* world_size
		self.orientation = random.random() * 2.0 * pi
		self.forward_noise = 0.0 
		self.turn_noise = 0.0
		self.sense_noise = 0.0 
 		
	def set(self, new_x, new_y, new_orientation):
		if new_x < 0 or new_x >= world_size:
			raise Value Error, 'X coordinate out of bound'
		if new_y < 0 or new_y >= world_size:
			raise Value Error, 'Y coordinate out of bound'
		if new_orientation< 0 or new_orientation >= 2 * pi:
			raise Value Error, 'Orientation out of bound'		
		self.x = float(new_x)
		self.y = float(new_y)
		self.orientation = float(new_orientation)
		
	def set_noise(self, new_f_noise, new_t_noise, new_s_noise):
		self.forward_noise =  float(new_f_noise)
		self.turn_noise = float(new_t_noise)
		self.sense_noise = float(new_s_noise)

	def sense(self):
		Z=[]
		for i in range(len(landmarks)):
			dist = sqrt((self.x - landmarks[i][0]) **2 + (self.y - landmaek[i][1])**2)
			dist += random.gauss(0.0, self.sense_noise)
			Z.appeend(dist)
		return Z
	
	def move(self, turn, forward):
        	if forward < 0:
            		raise ValueError, 'Robot cant move backwards'         
        
        	# turn, and add randomness to the turning command
        	orientation = self.orientation + float(turn) + random.gauss(0.0, self.turn_noise)
        	orientation %= 2 * pi
        
        	# move, and add randomness to the motion command
        	dist = float(forward) + random.gauss(0.0, self.forward_noise)
        	x = self.x + (cos(orientation) * dist)
        	y = self.y + (sin(orientation) * dist)
        	x %= world_size    # cyclic truncate
        	y %= world_size
        
        	# set particle
        	res = robot()
        	res.set(x, y, orientation)
        	res.set_noise(self.forward_noise, self.turn_noise, self.sense_noise)
        	return res
    	
	def Gaussian(self, mu, sigma, x):       
        	# calculates the probability of x for 1-dim Gaussian with mean mu and var. sigma
        	return exp(- ((mu - x) ** 2) / (sigma ** 2) / 2.0) / sqrt(2.0 * pi * (sigma ** 2))
	
	
	def measurement_prob(self, measurement):
		prob=1.0;
		for i in range(len(landmarks)):
			dist = sqrt((self.x - landmarks[i][0])**2 + (self.y - landmarks[i][1])**2)
			prob *= self.Gaussian(dist, self.sense_noise, measurement[i])
			return prob 
	
	def __repr__(self):
        	return '[x=%.6s y=%.6s orient=%.6s]' % (str(self.x), str(self.y), str(self.orientation))
	
	def eval(r, p):
    		sum = 0.0;
    		for i in range(len(p)): # calculate mean error
        	dx = (p[i].x - r.x + (world_size/2.0)) % world_size - (world_size/2.0)
        	dy = (p[i].y - r.y + (world_size/2.0)) % world_size - (world_size/2.0)
        	err = sqrt(dx * dx + dy * dy)
        	sum += err
    		return sum / float(len(p))





################################################################################################

landmarks= [[20.0,20.0],
	    [80.0,80.0],
	    [20.0,80.0],
	    [80.0,20.0]]

world_size=100.0



#Intialize robot model 

myrobot = robot()
myrobot = myrobot.move(0.1, 5.0)
Z= myrobot.sense()
#print Z
#print myrobot

T = 10 #Leave this as 10 for grading purposes
#################################################################################################################################################################


##creating random particles

N = 1000
P = [] 
for i in range(N):
	x = robot()
	x.set_noise(0.05, 0.05, 5.0)
	P.append(x)
print len(P)

#print P


for t in range(T):

	myrobot = myrobot.move(0.1, 5.0)
	Z = myrobot.sense()
	
	##Making particels simulate robot motion
	
	P2=[]
	for i in range(N):
		P2.append(P[i].move(0.1,5.0))
	P=P2
	
	#print P
	
	
	##creating importance weight for particels 

	W=[]
	for i in range(N):
		W.append(P[i].measurement_prob(Z))

	#print W

	## resampling 
	P3 = []
	index = int(random.random() * N)
	beta =0.0
	Max_Wight = max(W)
	for i in range(N):
		beta+= random.random()*2.0*Max_Wight
		while beta > W[index]:
			beta -= W[index]
			index = (index+ 1) % N
		
		P3.append(p[index])
	P=P3
	#print P
	
	print eval(myrobot, P)
