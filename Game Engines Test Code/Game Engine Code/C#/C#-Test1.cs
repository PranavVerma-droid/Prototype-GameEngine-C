using System.Collections.Generic;

public class GameEngine {
    private List<GameObject> _gameObjects;
    private GraphicsEngine _graphicsEngine;
    private PhysicsEngine _physicsEngine;
    private AudioEngine _audioEngine;
    private ScriptEngine _scriptEngine;

    public GameEngine() {
        _gameObjects = new List<GameObject>();
        _graphicsEngine = new GraphicsEngine();
        _physicsEngine = new PhysicsEngine();
        _audioEngine = new AudioEngine();
        _scriptEngine = new ScriptEngine();
    }

    public void Update(float deltaTime) {
        // Update all game objects
        foreach (GameObject gameObject in _gameObjects) {
            gameObject.Update(deltaTime);
        }

        // Update physics simulation
        _physicsEngine.Update(deltaTime);

        // Update audio engine
        _audioEngine.Update(deltaTime);

        // Update script engine
        _scriptEngine.Update(deltaTime);
    }

    public void Render() {
        // Render all game objects
        foreach (GameObject gameObject in _gameObjects) {
            _graphicsEngine.Render(gameObject);
        }
    }

    public void AddGameObject(GameObject gameObject) {
        _gameObjects.Add(gameObject);
    }

    public void RemoveGameObject(GameObject gameObject) {
        _gameObjects.Remove(gameObject);
    }
}
