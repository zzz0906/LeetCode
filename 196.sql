DELETE p2 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p2.Id > p1.Id;