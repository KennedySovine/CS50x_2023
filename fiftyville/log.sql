-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Find a description of a CSR with the same year, month, day, and street as the crime
SELECT id
FROM crime_scene_reports
WHERE year = "2020"
    AND month = "7"
    AND day = "28"
    AND street = "Chamberlin Street"
--ID : 295

SELECT description
FROM crime_scene_reports
WHERE id = "295"
--Time: 10:15 am
--Location: courthouse
--3 witnessess (conducted today)

SELECT id
FROM interviews
WHERE year = "2020"
    AND month = "7"
    AND day = "28"
--ID: 158, 159, 160, 161, 162, 163

--Check which IDS are usable 
SELECT transcript
FROM interviews
WHERE id = "(id)"
--IDS: 161, 162, 163

SELECT transcript
FROM interviews
WHERE id = "161"
--Got into a car within 10 minutes of crime
--Look for cars that left parking lot within time frame

SELECT transcript
FROM interviews
WHERE id = "162"
--Someone they recognized
--Earlier morning, saw thief withdrawing money at ATM
--ATM location --> Fifer Street

SELECT transcript
FROM interviews
WHERE id = "163"
--Planning on the earliest flight out of town tomorrow
--Accomplice purchased
--Call less than a minute

SELECT name
FROM people
    JOIN courthouse_security_logs
    ON people.license_plate = courthouse_security_logs.license_plate
WHERE 
    year = "2020"
    AND month = "7"
    AND day = "28"
    AND hour = "10"
    AND minute >= "15"
    AND minute <= "25"
    AND activity = "exit"
--Names: Patrick, Ernest, Amber, Danielle, Roger, Elizabeth, Russel, Evelyn

SELECT name
FROM people
    JOIN bank_accounts
        ON people.id = bank_accounts.person_id
    JOIN atm_transactions
        ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    year = "2020"
    AND month = "7"
    AND day = "28"
    AND atm_location = "Fifer Street"
    AND transaction_type = "withdraw"
--Ernest, Russel, Roy, Bobby, Elizabeth, Danielle, Madison, Victoria

SELECT name
FROM people
    JOIN passengers
    ON people.passport_number = passengers.passport_number
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE year = "2020"
        AND month = "7"
        AND day = "29"
    ORDER BY hour, minute
    LIMIT 1
)
--Doris, Roger, Ernest, Edwars, Evenlyn, Madison, Bobby, Danielle

SELECT name
FROM people
    JOIN phone_calls
        ON people.phone_number = phone_calls.caller
WHERE day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"
    
--ADD IT ALL TOGETHER BABY
SELECT name
FROM people
    JOIN courthouse_security_logs
    ON people.license_plate = courthouse_security_logs.license_plate
WHERE 
    year = "2020"
    AND month = "7"
    AND day = "28"
    AND hour = "10"
    AND minute >= "15"
    AND minute <= "25"
    AND activity = "exit"
INTERSECT
SELECT name
FROM people
    JOIN bank_accounts
        ON people.id = bank_accounts.person_id
    JOIN atm_transactions
        ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    year = "2020"
    AND month = "7"
    AND day = "28"
    AND atm_location = "Fifer Street"
    AND transaction_type = "withdraw"
INTERSECT
SELECT name
FROM people
    JOIN passengers
    ON people.passport_number = passengers.passport_number
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE year = "2020"
        AND month = "7"
        AND day = "29"
    ORDER BY hour, minute
    LIMIT 1
)
INTERSECT
SELECT name
FROM people
    JOIN phone_calls
        ON people.phone_number = phone_calls.caller
WHERE day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"
    
--ERNEST

SELECT name
FROM people
    JOIN phone_calls
        ON people.phone_number = phone_calls.receiver
WHERE day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"
    AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Ernest"
) --Bertholdt

SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = "2020"
        AND month = "7"
        AND day = "29"
    ORDER BY hour, minute
    LIMIT 1
)