#ifndef ANAGRAMSSOLVERMODEL_H
#define ANAGRAMSSOLVERMODEL_H

#include <QFile>
#include <QTextStream>
#include <QHash>

class AnagramsSolverModel
{
public:
    void importDictionaryFile();
    QList<QString> generateSolutions(QString& anagram);
private:
    inline quint32 generateHash(QString& string);
    inline bool isMatch(quint32 hash, size_t index);
    QList<quint32> m_DictionaryHashes;
    QList<QString> m_DictionaryStrings;
};

#endif // ANAGRAMSSOLVERMODEL_H
