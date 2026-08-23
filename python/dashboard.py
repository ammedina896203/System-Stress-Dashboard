import pandas as pd
import plotly.graph_objects as go
import matplotlib.pyplot as plt
import time

CSV_PATH = r"C:\Users\ammed\OneDrive\Pictures\Documents\Projects\stress_monitor\cpp\stress_data.csv"

def read_latest_score():
    df = pd.read_csv(CSV_PATH)
    return df[" Stress_Score"].iloc[-1]

def read_history():
    df = pd.read_csv(CSV_PATH)
    return df[" Stress_Score"].tolist()

plt.ion()
fig, ax = plt.subplots(figsize=(8,4))

def update_chart():
    history = read_history()
    ax.clear()
    ax.plot(history, color="purple")
    ax.set_title("Stress Score Over Time")
    ax.set_xlabel("Samples")
    ax.set_ylabel("Stress Score")
    fig.canvas.draw()
    fig.canvas.flush_events()

def show_gauge(score):
    fig = go.Figure(go.Indicator(
        mode="gauge+number",
        value=score,
        title={'text': "Stress Score"},
        gauge={
            'axis': {'range': [0, 100]},
            'bar': {'color': "black"},
            'steps': [
                {'range': [0, 45], 'color': "green"},
                {'range': [45, 80], 'color': "yellow"},
                {'range': [80, 100], 'color': "red"}
            ]
        }
    ))

    fig.show()

score = read_latest_score()
show_gauge(score)

while True:
    update_chart()
    time.sleep(1)