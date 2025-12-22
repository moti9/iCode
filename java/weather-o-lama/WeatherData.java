
import java.util.ArrayList;
import java.util.List;


public class WeatherData implements Subject {
    private List<Observer> observers;
    private float temperature;
    private float humidity;
    private float pressure;

    public WeatherData() {
        this.observers = new ArrayList<>();
    }

    @Override
    public void registerObserver(Observer o) {
        this.observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        this.observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : this.observers) {
            observer.update();
        }
    }

    @Override
    public void measurementChanged() {
        notifyObservers();
    }

    @Override
    public void setMeasurements(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementChanged();
    }

    @Override
    public float getTemperature() {
        return this.temperature;
    }

    @Override
    public float getHumidity() {
        return this.humidity;
    }
   
    @Override
    public float getPressure() {
        return this.pressure;
    }

}