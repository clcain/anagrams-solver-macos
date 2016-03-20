#include "anagramssolvermodel.h"

void AnagramsSolverModel::importDictionaryFile()
{
    QFile file(":/dictionary/words.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream fileStream(&file);
    while (!fileStream.atEnd())
    {
        QString dictionaryString = fileStream.readLine();
        m_DictionaryStrings << dictionaryString;
        quint32 dictionaryHash = generateHash(dictionaryString);
        m_DictionaryHashes << dictionaryHash;
    }
}

QList<QString> AnagramsSolverModel::generateSolutions(QString& anagram)
{
    quint32 anagramHash = generateHash(anagram);
    QList<QString> solutions;
    for (int i = 0; i < m_DictionaryHashes.length(); i++)
    {
        if (isMatch(anagramHash, i))
        {
            solutions << m_DictionaryStrings.at(i);
        }
    }
    return solutions;
}

inline quint32 AnagramsSolverModel::generateHash(QString& string)
{
    QList<QChar> charList;
    for (int i = 0; i < string.length(); i++)
    {
        charList << string.at(i);
    }
    qSort(charList);
    QString sortedString;
    for (int i = 0; i < charList.length(); i++)
    {
        sortedString.append(charList.at(i));
    }
    quint32 hash = qHash(sortedString);
    return hash;
}

inline bool AnagramsSolverModel::isMatch(quint32 hash, size_t index)
{
    if (hash == m_DictionaryHashes.at(index))
    {
        return true;
    }
    return false;
}
