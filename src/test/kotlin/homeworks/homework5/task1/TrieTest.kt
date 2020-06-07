package homeworks.homework5.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertFalse
import org.junit.jupiter.api.Test
import java.io.File
import java.io.FileInputStream
import java.io.FileOutputStream
import java.io.OutputStream

internal class TrieTest {
    @Test
    fun size_EmptyTrie() {
        val trie = Trie(Node())
        assertEquals(0, trie.getQuantityOfWords())
    }

    @Test
    fun size_TwoElements() {
        val trie = Trie(Node())
        trie.add("aab")
        trie.add("abc")
        assertEquals(2, trie.getQuantityOfWords())
    }

    @Test
    fun size_OneElement() {
        val trie = Trie(Node())
        trie.add("aab")
        assertEquals(1, trie.getQuantityOfWords())
    }

    @Test
    fun size_AddSeveralEqualElements() {
        val trie = Trie(Node())
        trie.add("aab")
        trie.add("aab")
        trie.add("aab")
        assertEquals(1, trie.getQuantityOfWords())
    }

    @Test
    fun size_AllElementsWithEqualPrefix() {
        val trie = Trie(Node())
        trie.add("a")
        trie.add("ab")
        trie.add("abc")
        assertEquals(3, trie.getQuantityOfWords())
    }

    @Test
    fun contains_AllElementsWithEqualPrefix() {
        val trie = Trie(Node())
        trie.add("a")
        trie.add("ab")
        trie.add("abc")
        assert(trie.contains("ab"))
    }

    @Test
    fun contains_AllElementsWithNotEqualPrefix() {
        val trie = Trie(Node())
        trie.add("abc")
        trie.add("bbc")
        trie.add("cbc")
        assert(trie.contains("cbc"))
    }

    @Test
    fun contains_AllElementsWithNotEqualPrefixNotContains() {
        val trie = Trie(Node())
        trie.add("abc")
        trie.add("bbc")
        trie.add("cbc")
        assertFalse(trie.contains("bc"))
    }

    @Test
    fun contains_OneElementContains() {
        val trie = Trie(Node())
        trie.add("abc")
        assert(trie.contains("abc"))
    }

    @Test
    fun contains_OneElementNotContains() {
        val trie = Trie(Node())
        trie.add("abc")
        assertFalse(trie.contains("cba"))
    }

    @Test
    fun contains_EmptyTrie() {
        val trie = Trie(Node())
        assertFalse(trie.contains("cba"))
    }

    @Test
    fun addAndRemove_emptyTrie() {
        val trie = Trie(Node())
        val emptyTrie = Trie(Node())
        trie.add("1bc")
        trie.remove("1bc")
        assert(trie.equal(emptyTrie))
    }

    @Test
    fun addAndRemove_TrieWithChainOfCharactersInTheEnd() {
        val actualTrie = Trie(Node())
        val expectedTrie = Trie(Node())
        actualTrie.add("a")
        actualTrie.add("ab")
        actualTrie.add("abc")
        actualTrie.add("abcd")
        actualTrie.remove("abcd")

        expectedTrie.add("a")
        expectedTrie.add("ab")
        expectedTrie.add("abc")

        assert(actualTrie.equal(expectedTrie))
    }

    @Test
    fun addAndRemove_TrieWithChainOfCharactersInTheMiddle() {
        val actualTrie = Trie(Node())
        val expectedTrie = Trie(Node())
        actualTrie.add("a")
        actualTrie.add("ab")
        actualTrie.add("abc")
        actualTrie.add("abcd")
        actualTrie.remove("ab")

        expectedTrie.add("a")
        expectedTrie.add("abcd")
        expectedTrie.add("abc")
        assert(actualTrie.equal(expectedTrie))
    }

    @Test
    fun serialize_complicatedTrie() {
        val trieForSerialize = Trie(Node())
        val out =
            FileOutputStream("./src/test/resources/homeworks/homework5/task1/TestSerializeComplicatedTrie.txt")
        trieForSerialize.add("a")
        trieForSerialize.add("abc")
        trieForSerialize.add("ab")
        trieForSerialize.add("fg")
        trieForSerialize.add("acb")
        trieForSerialize.serialize(out)
        val expected =
            File("./src/test/resources/homeworks/homework5/task1/TestSerializeComplicatedTrie.txt").readText()
        val actual =
            File("./src/test/resources/homeworks/homework5/task1/SerializeComplicatedTrie.txt").readText()
        assertEquals(expected, actual)
    }

    @Test
    fun serialize_emptyTrie() {
        val trieForSerialize = Trie(Node())
        val out = FileOutputStream("./src/test/resources/homeworks/homework5/task1/TestSerializeEmptyTrie.txt")
        trieForSerialize.serialize(out)
        val expected =
            File("./src/test/resources/homeworks/homework5/task1/TestSerializeEmptyTrie.txt").readText()
        val actual = File("./src/test/resources/homeworks/homework5/task1/SerializeEmptyTrie.txt").readText()
        assertEquals(expected, actual)
    }

    @Test
    fun deserialize_emptyTrie() {
        val trieForDeserialize = Trie.deserialize(
            FileInputStream("./src/test/resources/homeworks/homework5/task1/SerializeEmptyTrie.txt")
        )
        val actualTrie = Trie(Node())
        assert(actualTrie.equal(trieForDeserialize))
    }

    @Test
    fun deserialize_bigComplicatedTrie() {
        val trieForDeserialize = Trie.deserialize(
            FileInputStream("./src/test/resources/homeworks/homework5/task1/SerializeComplicatedTrie.txt")
        )
        val actualTrie = Trie(Node())
        actualTrie.add("a")
        actualTrie.add("abc")
        actualTrie.add("ab")
        actualTrie.add("fg")
        actualTrie.add("acb")
        assert(actualTrie.equal(trieForDeserialize))
    }

    @Test
    fun howManyStartWithPrefix_allWithEqualPrefix() {
        val trie = Trie(Node())
        trie.add("abc")
        trie.add("abd")
        trie.add("abe")
        trie.add("ab")
        trie.add("abcd")
        print(trie.serialize(OutputStream.nullOutputStream()))
        assertEquals(5, trie.howManyStartWithPrefix("ab"))
    }

    @Test
    fun howManyStartWithPrefix_allWithDifferentPrefixes() {
        val trie = Trie(Node())
        trie.add("abc")
        trie.add("leads")
        trie.add("fddf")
        trie.add("bu")
        trie.add("unt")
        assertEquals(1, trie.howManyStartWithPrefix("u"))
    }

    @Test
    fun howManyStartWithPrefix_equalAndDifferentPrefixes() {
        val trie = Trie(Node())
        trie.add("abc")
        trie.add("leads")
        trie.add("ab")
        trie.add("bu")
        trie.add("unt")
        assertEquals(2, trie.howManyStartWithPrefix("a"))
    }
}
