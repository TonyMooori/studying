import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

if __name__=="__main__":
    data = pd.read_csv("DATA_128_WEIGHT_12.csv")
    plt.plot(data['x'],data['y'])
    plt.show()