A memory leaak means:
- "I asked for heap memory using new, but I never gave it back using delete."

Example bug:
int* value = new int(10);
// forgot delete
