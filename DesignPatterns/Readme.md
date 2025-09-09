1. Creational Patterns

Focus: Object creation mechanisms — make system independent of how objects are created.

Singleton → Ensure a class has only one instance (e.g., DB connection). 

Factory Method → Define an interface for creating objects, but let subclasses decide.

Abstract Factory → Create families of related objects without specifying concrete classes.

Builder → Step-by-step creation of complex objects (e.g., building a house).

Prototype → Create objects by copying an existing object (cloning).

🔹 2. Structural Patterns

Focus: Composition of classes/objects — how to structure code for flexibility and reuse.

Adapter → Converts one interface into another (like charging adapters).

Bridge → Decouple abstraction from implementation (e.g., remote + device).

Composite → Tree structure for part-whole hierarchy (folders/files).

Decorator → Add new behavior dynamically without modifying class.

Facade → Provide a simplified interface to a complex subsystem.

Flyweight → Share common objects to save memory (e.g., characters in a text editor).

Proxy → Placeholder for another object (e.g., virtual proxy for lazy loading).

🔹 3. Behavioral Patterns

Focus: Object communication & responsibility distribution.

Observer → One-to-many dependency (publish-subscribe).

Strategy → Define family of algorithms, make them interchangeable.

Command → Encapsulate request as an object (undo/redo operations).

Chain of Responsibility → Pass request along chain of handlers.

Mediator → Centralize communication between objects.

Memento → Save/restore object state (undo functionality).

State → Change behavior when internal state changes (e.g., TCP connection states).

Template Method → Define skeleton of algorithm, let subclasses override steps.

Visitor → Separate algorithm from object structure.

Interpreter → Define grammar and evaluate sentences.

Iterator → Sequential access to elements without exposing underlying structure.

🔹 4. Concurrency (Multithreading) Patterns (less common, but important)

Thread Pool → Reuse limited number of threads.

Read-Write Lock → Allow multiple readers, single writer.

Producer-Consumer → Buffer-based communication.

Future/Promise → Represent result of async computation.