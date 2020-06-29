--Consolidated queries for problem set 7 into a single document.
-- 


SELECT title FROM movies WHERE year = 2008;



SELECT birth FROM people WHERE name = "Emma Stone";



SELECT title FROM movies WHERE year >= 2018
ORDER BY title ASC;



SELECT COUNT(*) FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = 10.0);



SELECT title, year FROM movies WHERE title LIKE "Harry Potter%"
ORDER BY year ASC;



SELECT avg(rating) AS "Average Rating"
FROM ratings
WHERE movie_id IN (
    SELECT id
    FROM movies
    WHERE year = 2012
);



SELECT
    title,
    rating
FROM
    movies
LEFT JOIN ratings ON
    ratings.movie_id = movies.id
WHERE year IS 2010 and rating IS NOT NULL
ORDER BY rating DESC, title ASC;



SELECT name
FROM people
WHERE id IN
    (SELECT person_id
    FROM stars
    WHERE movie_id IN
        (SELECT id
        from movies
        WHERE title = "Toy Story")
    );
    
    
SELECT
    name
FROM
    people
WHERE id IN (
    SELECT
        person_id
    FROM
        stars
    WHERE movie_id IN
        (SELECT id FROM movies WHERE year = 2004))
ORDER BY birth ASC;
         
         
         
SELECT
    name
FROM
    people
WHERE id IN (
    SELECT
        person_id
    FROM
        directors
    WHERE movie_id IN
        (SELECT movie_id FROM ratings WHERE rating >= 9.0));

         
         
         
      
 SELECT
    title as "Movie Title"
FROM
    movies
LEFT JOIN ratings ON
    ratings.movie_id = movies.id
WHERE id IN (
    SELECT
        movie_id
    FROM
        stars
    WHERE person_id IN
        (SELECT id FROM people WHERE name = "Chadwick Boseman")
)
ORDER BY rating DESC
LIMIT 5;
         
         
         
         
         
SELECT title
FROM movies

    WHERE movies.id IN (
            SELECT movie_id
            FROM stars
            WHERE person_id IN(
                            SELECT id
                            FROM people
                            WHERE name = "Johnny Depp"))

    AND movies.id IN (
            SELECT movie_id
            FROM stars
            WHERE person_id IN(
                            SELECT id
                            FROM people
                            WHERE name = "Helena Bonham Carter"));

              
              
              
              
              
SELECT people.name
FROM movies
    
LEFT JOIN stars ON
    stars.movie_id = movies.id
LEFT JOIN people ON
    people.id = stars.person_id
    
    WHERE movies.id IN (
            SELECT movie_id
            FROM stars
            WHERE person_id IN(
                            SELECT id
                            FROM people
                            WHERE name = "Kevin Bacon" AND birth = "1958"))
    
    AND person_id IN (
                            SELECT id
                            FROM people
                            WHERE NOT name == "Kevin Bacon");
