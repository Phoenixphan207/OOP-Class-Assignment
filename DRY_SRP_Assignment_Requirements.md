# Assignment: DRY & SRP — Use Them Wisely

## Goal

Research two software design principles:

- **DRY (Don't Repeat Yourself):** avoid repeating the same knowledge or logic.
- **SRP (Single Responsibility Principle):** keep a class or module focused on one responsibility.

The goal is not to apply these principles everywhere. Learn what they mean, when they help, and when applying them too aggressively makes code worse.

**Format:** Individual assignment  
**Deliverables:** PDF report + source code for examples  
**Suggested length:** 10-20 pages

---

## Part 1 — Basic Research

### A. DRY

Research and explain:

1. What does DRY mean, and what problem does it solve?
2. What kinds of duplication can appear in software?
3. Why can duplicated logic cause problems when requirements change?
4. What are common ways to reduce duplication?

**Practical example:** Show code with a genuine DRY problem. Explain the duplication, refactor it, and explain why the new version is better.

### B. SRP

Research and explain:

1. What does SRP mean?
2. What does “one reason to change” mean?
3. What is a responsibility in a class or module?
4. How can you recognize when a class has unrelated responsibilities?
5. How can you separate those responsibilities?

**Practical example:** Show a class that genuinely violates SRP. Explain its responsibilities, refactor it, and explain why the new design is better.

---

## Part 2 — Advanced: Misuse, Overuse, and Trade-offs

This is the main focus. Don't just explain how to apply the principles. Think about when applying them can make the design worse.

### A. DRY: Is Less Duplication Always Better?

Research and discuss:

1. Is all similar-looking code worth combining?
2. Can shared code create unwanted dependencies?
3. What is premature abstraction, and why can it be a problem?
4. When is keeping some duplication simpler or safer?

**Provide two examples:**

- **DRY overuse:** A developer combines code that should remain separate, or creates an unnecessarily complex abstraction.
- **Acceptable duplication:** Two pieces of similar code represent different business rules and should reasonably evolve independently.

Explain the context and trade-offs. You do not have to refactor an example if you believe the original design is better.

### B. SRP: Does Every Responsibility Need Its Own Class?

Research and discuss:

1. Does SRP mean one class should have only one method?
2. Can a class with many methods still have one clear responsibility?
3. What problems can too many small classes create?
4. Can excessive interfaces, wrappers, or layers make code harder to understand?
5. How do cohesion and coupling help when deciding whether to split a class?

**Provide two examples:**

- **SRP overuse:** A developer creates too many small classes or unnecessary layers.
- **Acceptable grouping:** A class has several related methods that reasonably belong together.

Explain the context and trade-offs. You do not have to refactor an example if you believe the original design is better.

### C. Your Design Judgment

Answer these questions:

1. Are DRY and SRP strict rules or guidelines? Why?
2. How do you decide whether a refactoring is worth doing?
3. What should you consider before extracting shared code or splitting a class?
4. Describe one situation where you would deliberately avoid applying DRY or SRP more aggressively.

Give reasons and examples. “It depends” is not enough—explain what it depends on.

---

## Part 3 — Code Review

For each scenario, decide whether it is a **violation**, a **potential issue**, or **acceptable**. Explain your decision. Don't refactor just for the sake of refactoring.

1. **Shared validation:** Two operations contain the same customer validation logic, based on the same business policy. Should the logic be shared?
2. **Similar calculations:** Tax and discount modules contain the same formula today, but the rules come from different business policies. Should they share one method?
3. **Many methods:** A `Student` class updates student information, calculates GPA, checks academic status, and displays a summary. Does it violate SRP?
4. **Too many classes:** A developer creates `StudentNameGetter`, `StudentNameSetter`, `StudentAgeGetter`, and `StudentAgeSetter`. Is this good SRP?
5. **Order service:** An `OrderService` validates an order, calculates its total, saves it, and sends a confirmation email. Should these tasks be separated?

For each scenario, consider the context, possible reasons to change, benefits, and costs of changing the design.

---

## Report and Submission

Suggested report structure:

1. Introduction
2. Basic research: DRY and SRP
3. Advanced analysis: misuse, overuse, and trade-offs
4. Code review: five scenarios
5. Conclusion: what you learned and what you would do in practice
6. References

Submit:

- One PDF report.
- Source files for your practical examples (`.cpp`, `.h`, `.cs`, `.java`, etc.).
- Clear filenames and folders.
- At least **three credible references**. Cite sources and include URLs and access dates for websites.

Use your own words. You may use AI tools to support research, but check the information and make sure you understand and can explain all submitted code. You may be asked to explain or modify your examples.

---

## Evaluation — 100 points

| Criteria | Points |
|---|---:|
| Basic understanding of DRY | 10 |
| Basic understanding of SRP | 10 |
| DRY: identifying real problems and improving the design | 15 |
| DRY: recognizing overuse and acceptable duplication | 15 |
| SRP: identifying real problems and improving the design | 15 |
| SRP: recognizing overuse and reasonable grouping | 15 |
| Code review, reasoning, and trade-off analysis | 15 |
| Report quality and references | 5 |
| **Total** | **100** |

High marks are for clear reasoning, realistic examples, and good design decisions—not for creating the most classes or abstractions.

---

## Keep in Mind

> **Design principles are guidelines, not rules to follow blindly.**

The goal is not to remove every bit of duplication or split every class. The goal is to make code easier to understand, maintain, and change without adding unnecessary complexity.

A good developer knows not only how to apply a principle, but also **when to apply it—and when to stop**.
