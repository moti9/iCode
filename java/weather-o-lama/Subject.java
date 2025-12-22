public interface Subject {
    public void registerObserver(Observer o);
    public void removeObserver(Observer o);
    public void notifyObservers();
    public void setMeasurements(float temperature, float humidity, float pressure);
    public void measurementChanged();
    public float getTemperature();
    public float getHumidity();
    public float getPressure();

}
