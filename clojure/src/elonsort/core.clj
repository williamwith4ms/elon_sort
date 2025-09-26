(ns elonsort.core)

(defn gen-prob
  "flip a coin based off a given probability"
  [x]
  (< (rand) x)
)

(defn decide-for-element
  "takes an element, and decided if it should exist"
  [x]
  (if (gen-prob 0.5)
    (list x)
  )
)

(defn elon-sort
  "takes a list, and \"sorts\" it"
  [x]
  (remove nil? (concat (map decide-for-element x))) 
)
