package homeworks.homework5.task1

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test
import java.io.File
import java.io.FileInputStream
import java.io.FileOutputStream
import java.io.OutputStream

internal class TrieTest {
    @Test
    fun size_EmptyTrie() {
        val trie = Trie()
        assertEquals(0, trie.size())
    }

    @Test
    fun size_TwoElements() {
        val trie = Trie()
        trie.add("aab")
        trie.add("abc")
        assertEquals(2, trie.size())
    }

    @Test
    fun size_OneElement() {
        val trie = Trie()
        trie.add("aab")
        assertEquals(1, trie.size())
    }

    @Test
    fun size_AddSeveralEqualElements() {
        val trie = Trie()
        trie.add("aab")
        trie.add("aab")
        trie.add("aab")
        assertEquals(1, trie.size())
    }

    @Test
    fun size_AllElementsWithEqualPrefix() {
        val trie = Trie()
        trie.add("a")
        trie.add("ab")
        trie.add("abc")
        assertEquals(3, trie.size())
    }

    @Test
    fun contains_AllElementsWithEqualPrefix() {
        val trie = Trie()
        trie.add("a")
        trie.add("ab")
        trie.add("abc")
        assert(trie.contains("ab"))
    }

    @Test
    fun contains_AllElementsWithNotEqualPrefix() {
        val trie = Trie()
        trie.add("abc")
        trie.add("bbc")
        trie.add("cbc")
        assert(trie.contains("cbc"))
    }

    @Test
    fun contains_AllElementsWithNotEqualPrefixNotContains() {
        val trie = Trie()
        trie.add("abc")
        trie.add("bbc")
        trie.add("cbc")
        assertFalse(trie.contains("bc"))
    }

    @Test
    fun contains_OneElementContains() {
        val trie = Trie()
        trie.add("abc")
        assert(trie.contains("abc"))
    }

    @Test
    fun contains_OneElementNotContains() {
        val trie = Trie()
        trie.add("abc")
        assertFalse(trie.contains("cba"))
    }

    @Test
    fun contains_EmptyTrie() {
        val trie = Trie()
        assertFalse(trie.contains("cba"))
    }

    @Test
    fun addAndRemove_emptyTrie() {
        val trie = Trie()
        val emptyTrie = Trie()
        trie.add("1bc")
        trie.remove("1bc")
        assert(trie.equalToTrie(emptyTrie))
    }

    @Test
    fun addAndRemove_TrieWithChainOfCharactersInTheEnd() {
        val actualTrie = Trie()
        val expectedTrie = Trie()
        actualTrie.add("a")
        actualTrie.add("ab")
        actualTrie.add("abc")
        actualTrie.add("abcd")
        actualTrie.remove("abcd")

        expectedTrie.add("a")
        expectedTrie.add("ab")
        expectedTrie.add("abc")
        assert(actualTrie.equalToTrie(expectedTrie))
    }

    @Test
    fun addAndRemove_TrieWithChainOfCharactersInTheMiddle() {
        val actualTrie = Trie()
        val expectedTrie = Trie()
        actualTrie.add("a")
        actualTrie.add("ab")
        actualTrie.add("abc")
        actualTrie.add("abcd")
        actualTrie.remove("ab")

        expectedTrie.add("a")
        expectedTrie.add("abcd")
        expectedTrie.add("abc")
        assert(actualTrie.equalToTrie(expectedTrie))
    }

    @Test
    fun serialize_complicatedTrie() {
        val trieForSerialize = Trie()
        val out = FileOutputStream("./src/test/resources/homeworks/homework5/task1/TestSerializeComplicatedTrie.txt")
        trieForSerialize.add("a")
        trieForSerialize.add("abc")
        trieForSerialize.add("ab")
        trieForSerialize.add("fg")
        trieForSerialize.add("acb")
        trieForSerialize.serialize(out)
        val expected = File("./src/test/resources/homeworks/homework5/task1/TestSerializeComplicatedTrie.txt").readText()
        val actual = File("./src/test/resources/homeworks/homework5/task1/SerializeComplicatedTrie.txt").readText()
        assertEquals(expected, actual)
    }

    @Test
    fun serialize_emptyTrie() {
        val trieForSerialize = Trie()
        val out = FileOutputStream("./src/test/resources/homeworks/homework5/task1/TestSerializeEmptyTrie.txt")
        trieForSerialize.serialize(out)
        val expected = File("./src/test/resources/homeworks/homework5/task1/TestSerializeEmptyTrie.txt").readText()
        val actual = File("./src/test/resources/homeworks/homework5/task1/SerializeEmptyTrie.txt").readText()
        assertEquals(expected, actual)
    }

    @Test
    fun deserialize_emptyTrie() {
        val trieForDeserialize = Trie()
        val actualTrie = Trie()
        val inp = FileInputStream("./src/test/resources/homeworks/homework5/task1/SerializeEmptyTrie.txt")
        trieForDeserialize.deserialize(inp)
        assert(actualTrie.equalToTrie(trieForDeserialize))
    }

    @Test
    fun deserialize_bigComplicatedTrie() {
        val trieForDeserialize = Trie()
        val actualTrie = Trie()
        actualTrie.add("a")
        actualTrie.add("abc")
        actualTrie.add("ab")
        actualTrie.add("fg")
        actualTrie.add("acb")
        val inp = FileInputStream("./src/test/resources/homeworks/homework5/task1/SerializeComplicatedTrie.txt")
        trieForDeserialize.deserialize(inp)
        assert(actualTrie.equalToTrie(trieForDeserialize))
    }

    @Test
    fun howManyStartWithPrefix_allWithEqualPrefix() {
        val trie = Trie()
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
        val trie = Trie()
        trie.add("abc")
        trie.add("leads")
        trie.add("fddf")
        trie.add("bu")
        trie.add("unt")
        assertEquals(1, trie.howManyStartWithPrefix("u"))
    }

    @Test
    fun howManyStartWithPrefix_equalAndDifferentPrefixes() {
        val trie = Trie()
        trie.add("abc")
        trie.add("leads")
        trie.add("ab")
        trie.add("bu")
        trie.add("unt")
        assertEquals(2, trie.howManyStartWithPrefix("a"))
    }
}
